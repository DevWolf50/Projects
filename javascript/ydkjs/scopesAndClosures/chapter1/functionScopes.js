//Create functions to make variables and code private. "Principle of Least"
//If you're going to create a function and the execute that function its better to use IIFE(Immediately Invoked Function Expression)
//consider

var name = "Joe";

(function yellSomething() { //hiding variables and code within a function including "yellSomething"
  var name = "Regina";
  alert(name); //regina
})(); //Immediately invokes the function with ()

alert(name); //Joe
