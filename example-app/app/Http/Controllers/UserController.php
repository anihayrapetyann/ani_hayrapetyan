<?php

namespace App\Http\Controllers;

use App\Jobs\TestJob;
use App\Models\User;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Cache;

class UserController extends Controller
{
    function addUser(Request $request){
        $user = new User;
      if($request->submit) {
          $request->validate([
              'uname' => 'required',
              'phone' => 'required|digits:6',
              'password' => 'required|min:5'
          ]);
          $user->user_name = $request->uname;
          $user->phone_number = $request->phone;
          $user->password = $request->password;
          $user->save();
          TestJob::dispatch()->onQueue('messege');

          return view('welcome', ['name' => $request->uname]);
      }
          $allUsers = $user->all();
          $userNames = $allUsers->pluck('user_name');
          Cache::put('key', $userNames, 60);

          return view( 'allusers', ['userNames' => $userNames]);
    }

}
