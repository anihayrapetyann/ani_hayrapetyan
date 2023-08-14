<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;

class UserController extends Controller
{
    function addUser(Request $request){
        $request->validate([
            'uname' => 'required',
            'phone' => 'required|digits:6',
            'password' => 'required|min:5'
        ]);
        $user = new User;
        $user->user_name = $request->uname;
        $user->phone_number = $request->phone;
        $user->password = $request->password;
        $user->save();

        return view('welcome', ['name'=>$request->uname]);

    }

}
