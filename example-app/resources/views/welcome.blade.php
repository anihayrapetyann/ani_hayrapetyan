<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>MySite</title>
    @vite(['resources/css/app.css', 'resources/js/app.js'])
</head>
<body>
<div class="welcome_div" >
    <h1 class="welcome">Welcome to MySite </h1><br>
    <h3 class="welcome">Your data has been successfully saved!!!</h3>
    <h3 class="username">Your username is {{$name}} </h3>

</div>

</body>
</html>
