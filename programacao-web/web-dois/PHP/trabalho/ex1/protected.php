<?php
session_start();

if (empty($_SESSION['valid']) || empty($_SESSION['username'])) {
    header('Location: login.php');
    exit;
}

$products = [
    ['id' => 1, 'name' => 'Camiseta', 'price' => 39.90],
    ['id' => 2, 'name' => 'Zorba', 'price' => 24.50],
    ['id' => 3, 'name' => 'Brusinha', 'price' => 48.00],
    ['id' => 4, 'name' => 'Meia', 'price' => 19.90],
    ['id' => 5, 'name' => 'Calça', 'price' => 89.00],
];

$username = $_SESSION['username'];
$safeUsernameForHtml = htmlspecialchars($username, ENT_QUOTES, 'UTF-8');
?>
<!doctype html>
<html lang="pt-BR">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>Loja - Produtos</title>
    <style>
        * {
            box-sizing: border-box;
        }

        body {
            font-family: Arial, Helvetica, sans-serif;
            background: #f4f6f8;
            margin: 0;
            padding: 0;
        }

        header {
            background: #1d72b8;
            color: #fff;
            padding: 12px 20px;
        }

        .main-wrap {
            max-width: 1100px;
            margin: 20px auto;
            padding: 20px;
            display: flex;
            gap: 20px;
            align-items: flex-start;
        }

        .container {
            flex: 1 1 auto;
            min-width: 0;
        }

        .products {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(220px, 1fr));
            gap: 16px;
        }

        .product {
            background: #fff;
            padding: 12px;
            border-radius: 6px;
            box-shadow: 0 1px 4px rgba(0, 0, 0, 0.06);
        }

        .product h3 {
            margin: 0 0 8px 0;
            font-size: 1.05rem;
        }

        .product .price {
            font-weight: bold;
            margin-top: 8px;
        }

        .cartContainer {
            flex: 0 0 320px;
        }

        .cart {
            background: #fff;
            padding: 12px;
            border-radius: 6px;
            box-shadow: 0 1px 4px rgba(0, 0, 0, 0.06);
            position: sticky;
            top: 20px;
        }

        .cart h3 {
            margin-top: 0;
        }

        .cart-list {
            list-style: none;
            padding: 0;
            margin: 0;
            max-height: 60vh;
            overflow: auto;
        }

        .cart-item {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 8px 0;
            border-bottom: 1px solid #eee;
        }

        .qty-controls button {
            width: 26px;
            height: 26px;
            cursor: pointer;
        }

        .actions {
            margin-top: 12px;
        }

        a.button {
            display: inline-block;
            padding: 8px 10px;
            background: #1d72b8;
            color: #fff;
            border-radius: 4px;
            text-decoration: none;
        }

        .small {
            font-size: 0.9rem;
            color: #666;
        }

        .clear-btn {
            background: #c0392b;
            padding: 6px 10px;
            color: #fff;
            border-radius: 4px;
            display: inline-block;
            text-decoration: none;
            border: none;
            cursor: pointer;
        }

        @media (max-width: 900px) {
            .main-wrap {
                flex-direction: column;
                padding: 12px;
            }

            .cartContainer {
                flex: 1 1 auto;
                width: 100%;
            }

            .cart {
                position: static;
            }
        }

        .product button {
            background: #1d72b8;
            color: #fff;
            border: none;
            padding: 8px 10px;
            border-radius: 4px;
            cursor: pointer;
        }
    </style>
</head>

<body>
    <header>
        <div style="max-width:1100px; margin:0 auto; display:flex;justify-content:space-between; align-items:center;">
            <div>Minha Loja de Teste</div>
            <div>Usuário: <strong><?= $safeUsernameForHtml ?></strong> — <a href="logout.php" style="color:#ffd; text-decoration:underline;">Sair</a></div>
        </div>
    </header>

    <div class="main-wrap">
        <div class="container">
            <div class="products" id="products">
                <?php foreach ($products as $p): ?>
                    <div class="product" data-id="<?= $p['id'] ?>" data-name="<?= htmlspecialchars($p['name'], ENT_QUOTES, 'UTF-8') ?>" data-price="<?= number_format($p['price'], 2, '.', '') ?>">
                        <h3><?= htmlspecialchars($p['name'], ENT_QUOTES, 'UTF-8') ?></h3>
                        <div class="small">Descrição rápida do produto.</div>
                        <div class="price">R$ <?= number_format($p['price'], 2, ',', '.') ?></div>
                        <div style="margin-top:8px;">
                            <button onclick="addToCart(<?= $p['id'] ?>)">Adicionar ao carrinho</button>
                        </div>
                    </div>
                <?php endforeach; ?>
            </div>
        </div>

        <div class="cartContainer">
            <aside class="cart">
                <h3>Seu Carrinho</h3>
                <ul class="cart-list" id="cartList"></ul>

                <div style="margin-top:12px;">
                    <strong>Total:</strong> R$ <span id="cartTotal">0.00</span>
                </div>

                <div class="actions">
                    <button onclick="clearCart()" class="clear-btn">Limpar carrinho</button>
                </div>
            </aside>
        </div>
    </div>

    <script>
        const CURRENT_USERNAME = <?= json_encode($username) ?>;
        const CART_COOKIE_NAME = 'cart_' + encodeURIComponent(CURRENT_USERNAME);

        function readCartFromCookie() {
            const cookies = document.cookie.split(';').map(c => c.trim());
            const item = cookies.find(c => c.startsWith(CART_COOKIE_NAME + '='));
            if (!item) return {};
            const value = item.substring((CART_COOKIE_NAME + '=').length);
            try {
                const decoded = decodeURIComponent(value);
                const parsed = JSON.parse(decoded);
                if (typeof parsed === 'object' && parsed !== null) return parsed;
                return {};
            } catch (e) {
                console.warn('Erro ao ler cookie do carrinho:', e);
                return {};
            }
        }

        function saveCartToCookie(cartObj) {
            try {
                const json = JSON.stringify(cartObj);
                const encoded = encodeURIComponent(json);
                const expires = new Date(Date.now() + 30 * 24 * 60 * 60 * 1000).toUTCString();
                document.cookie = `${CART_COOKIE_NAME}=${encoded}; path=/; expires=${expires}`;
            } catch (e) {
                console.error('Erro ao salvar cookie do carrinho:', e);
            }
        }

        function deleteCartCookie() {
            document.cookie = `${CART_COOKIE_NAME}=; path=/; expires=Thu, 01 Jan 1970 00:00:00 UTC`;
        }

        function formatBRL(num) {
            return num.toFixed(2).replace('.', ',');
        }

        function getProducts() {
            const nodes = document.querySelectorAll('#products .product');
            const map = {};
            nodes.forEach(n => {
                const id = n.getAttribute('data-id');
                map[id] = {
                    id: id,
                    name: n.getAttribute('data-name'),
                    price: parseFloat(n.getAttribute('data-price'))
                };
            });
            return map;
        }

        const PRODUCTS = getProducts();
        let cart = readCartFromCookie();
        renderCart();

        function addToCart(productId) {
            const id = String(productId);
            if (!PRODUCTS[id]) {
                alert('Produto inválido');
                return;
            }
            cart[id] = (cart[id] || 0) + 1;
            saveCartToCookie(cart);
            renderCart();
        }

        function removeFromCart(productId) {
            const id = String(productId);
            if (cart[id]) {
                delete cart[id];
                saveCartToCookie(cart);
                renderCart();
            }
        }

        function setQty(productId, qty) {
            const id = String(productId);
            qty = parseInt(qty) || 0;
            if (qty <= 0) {
                removeFromCart(id);
            } else {
                cart[id] = qty;
                saveCartToCookie(cart);
                renderCart();
            }
        }

        function clearCart() {
            cart = {};
            deleteCartCookie();
            renderCart();
        }

        function renderCart() {
            const list = document.getElementById('cartList');
            list.innerHTML = '';

            let total = 0;
            const keys = Object.keys(cart);
            if (keys.length === 0) {
                const li = document.createElement('li');
                li.className = 'small';
                li.textContent = 'Carrinho vazio.';
                list.appendChild(li);
            } else {
                keys.forEach(id => {
                    const qty = cart[id];
                    const p = PRODUCTS[id];
                    if (!p) return;
                    const lineTotal = p.price * qty;
                    total += lineTotal;

                    const li = document.createElement('li');
                    li.className = 'cart-item';
                    li.innerHTML = `
                        <div style="flex:1;">
                          <div><strong>${escapeHtml(p.name)}</strong></div>
                          <div class="small">R$ ${formatBRL(p.price)} x ${qty} = R$ ${formatBRL(lineTotal)}</div>
                        </div>
                        <div style="display:flex; gap:6px; align-items:center;">
                          <div class="qty-controls">
                            <button onclick="setQty(${p.id}, ${qty - 1})">−</button>
                            <input type="number" value="${qty}" min="1" style="width:50px; text-align:center;" onchange="setQty(${p.id}, this.value)">
                            <button onclick="setQty(${p.id}, ${qty + 1})">+</button>
                          </div>
                          <button onclick="removeFromCart(${p.id})" style="margin-left:6px; cursor:pointer;">Remover</button>
                        </div>
                    `;
                    list.appendChild(li);
                });
            }

            document.getElementById('cartTotal').textContent = formatBRL(total);
        }

        function escapeHtml(text) {
            return String(text)
                .replace(/&/g, '&amp;')
                .replace(/"/g, '&quot;')
                .replace(/'/g, '&#039;')
                .replace(/</g, '&lt;')
                .replace(/>/g, '&gt;');
        }
    </script>
</body>

</html>