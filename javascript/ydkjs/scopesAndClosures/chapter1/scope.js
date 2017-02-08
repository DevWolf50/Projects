//scope maintains a look up list of variables and a set of rules of accessing those variables

//consider

//global scope

var tax =0.45;

function addTax(a) { //function addTax scope

  return a + (a * tax); //when the engine uses scope to look up tax scope wont find it here it will have to traverse up to global scope
}

var total = addTax(15);

//Left Hand Side look ups:
//var tax
//var total
//(a) as an implicit paramter assignment

//Right Hand Side look ups:
// addTax(15)
//a +
//a *
//tax *
//(a * tax)
