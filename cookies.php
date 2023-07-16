<?php

//Cookies
//Creation of cookies
setcookie('user', "Aram", time() + 60);
if(isset($_COOKIE['user'])) {
    echo "Cookie is set";
}else {
    echo "Cookie isn't set";
}
echo "<br>". "User's name is ". $_COOKIE['user'];

//Deletion of cookie
setcookie('name', 5, time() - 360);

//Sessions
//Creation of session
session_start();
echo "<br>"."Session id: ". session_id();
echo "<br>"." session name: ". session_name();

$_SESSION['userId'] = 1;
$_SESSION['userName'] = 'Anna';
echo "<br>"."User id is ". $_SESSION['userId']."<br>"."Username is ".$_SESSION['userName']. "<br>";

//try-catch construction
try {
    $number1 = 5;
    $number2 = 0;
    $result = $number1 /$number2;
    echo $result;
} catch(DivisionByZeroError $ex) {
    echo $ex;
}

//Generating exceptions
class Person {
    private $name, $phoneNumber;

    /**
     * @throws Exception
     */
    function __construct($name, $phoneNumber)
    {
        if(substr($phoneNumber, 0, 3) !== "097") {
            throw new Exception("Your phone number isn't correct");
        }
        $this->name = $name;
        $this->phoneNumber = $phoneNumber;
    }
    function displayInfo() {
        echo "Name: $this->name "."<br>"."Phone Number: $this->phoneNumber";
    }
}

$tom = new Person("Hayk", "099221133");
$tom->displayInfo();














