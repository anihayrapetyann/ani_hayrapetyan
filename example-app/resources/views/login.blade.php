<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Mysite</title>
    @vite(['resources/css/app.css', 'resources/js/app.js'])
</head>
<body>
<div class="color">
    @if($errors->any())
        @foreach($errors->all() as $error)
            <div class="alert alert-danger" role="alert">
                {{$error}}!<br>
            </div>
        @endforeach
    @endif
</div>
    <div>
        <form  action="users" method="POST">
            <h1>MySite Login Page </h1>
            @csrf
            <label for="username">Username:</label><br>
{{--            {!! display_bootstrap_alerts() !!}--}}
            <input class="input" type="text" id="uname" name="uname" placeholder="Type your username"><br><br>
            <label for="psswrd">Password:</label><br>
            <input  class="input" type="password" id="psswrd" name="password" placeholder="Type your password"><br><br>
            <label for="phone">Phone Number:</label><br>
            <input  class="input" type="text" id="phone" name="phone" placeholder="Type your phone number"><br><br><br>
            <input name="submit" class="submit" type="submit" value="Login"><br><br>
            <input  name="allUsers" class="allUsers" type="submit" value="View all users">
        </form>

    </div>




</body>
</html>




