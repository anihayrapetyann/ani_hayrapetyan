<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\UserController;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/', function () {
   return view('login');
});

Route::post('/users', [\App\Http\Controllers\UserController::class, 'addUser']);

Route::get('localization/{locale}', [\App\Http\Controllers\LocalizationController::class, 'index']);

