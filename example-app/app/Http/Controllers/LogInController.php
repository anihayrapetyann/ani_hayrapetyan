<?php

namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use Illuminate\Http\RedirectResponse;
use Illuminate\Http\Request;
use Illuminate\View\View;

class LogInController extends Controller {
    public  function login(): View {
        return \view('home');
    }

    public function store(Request $request){
        $email = $request->input('email');

        return $email;
    }
}
