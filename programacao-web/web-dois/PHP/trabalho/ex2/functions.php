<?php

function registrations_file_path()
{
    return __DIR__ . '/registrations.json';
}

function load_all_registrations()
{
    $file = registrations_file_path();
    if (!file_exists($file)) return [];
    $json = @file_get_contents($file);
    $data = json_decode($json, true);
    return is_array($data) ? $data : [];
}

function save_all_registrations(array $all)
{
    $file = registrations_file_path();
    file_put_contents($file, json_encode($all, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE), LOCK_EX);
}

function get_user_registration($username)
{
    $all = load_all_registrations();
    return $all[$username] ?? [
        'personal' => [
            'full_name' => '',
            'birthdate' => '',
            'email' => '',
            'phone' => ''
        ],
        'address' => [
            'street' => '',
            'number' => '',
            'complement' => '',
            'city' => '',
            'state' => '',
            'zip' => ''
        ],
        'courses' => [
            'choice1' => '',
            'choice2' => '',
            'choice3' => ''
        ]
    ];
}

function save_user_registration($username, array $data)
{
    $all = load_all_registrations();
    $all[$username] = $data;
    save_all_registrations($all);
}
