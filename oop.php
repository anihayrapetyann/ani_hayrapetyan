<?php
// Classes and Objects
Class Animal {
    // properties
    public $name;
    public $color;
    // constructor
    function  __construct($name, $color) {
        $this->name = $name;
        $this->color = $color;
    }
    // methods
    function getName() {
        return $this->name;
    }
    function saySomething($string) {
        echo "\n $this->name says $string";
    }
    // destructor
    function __destruct () {
        echo "\n the $this->name was destructed";
    }
};

//object creation
$dog = new Animal("Daisy", "black");
echo $dog-> getName();
$dog-> saySomething("woof - woof");


class Phone {
   public $model;
    public $price;
    public $color;

    function __construct($model, $price, $color) {
        $this-> model = $model;
        $this->price = $price;
        $this->color = $color;
    }
    function displayInfo() {
        echo "model: $this->model \n price: $this->price \n color: $this->color";
    }

}
//inheritance
class Iphone extends Phone {
        public $password;
//        static property
        static $passwordLength = 6;
//        static method
        static function verifyPasswordLength ($password) {
            if(strlen($password) == self::$passwordLength) {
                echo "Your password was created successfully";
            }else {
                echo "Failed to create your password";
            }
        }
// overloading
    function displayInfo()
    {
       echo "I am iPhone";
    }
}
    $iphone = new Iphone("iphone 14 pro", "1500$", "black");
    $iphone->verifyPasswordLength("abcdef");

//Traits

Trait Hello {
	public function sayHello() {
		echo "Hello ";
	}
}

Trait World {
	public function SayWorld() {
		echo "World";
	}
}

class Greeting {
	use Hello, World;
}

 $greeting = new Greeting();
 $greeting-> sayHello();
 $greeting->sayWorld();
    
?>
