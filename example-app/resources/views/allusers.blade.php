<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Users List</title>
    @vite(['resources/css/app.css', 'resources/js/app.js'])

</head>
<body>
    <h3>MySite Users</h3>
    <ol>
        @foreach($userNames as $userName)

              <li>{{$userName}}</li><br>
        @endforeach
    </ol>
</body>
</html>
