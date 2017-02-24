function somethingCool(num, obj) {

  //TODO: comment
  var set = [1, 2, 3];

  function doSomething(a) {
    num += a;
    set.push(num);
    console.log("num:" + num );
    console.log("set:" + set);
    console.log("objectValue:" + obj.value);
  }

  return doSomething;
}

var refObject = {value: 5};

var foo = somethingCool(5, refObject);
var bar = somethingCool(10, refObject);

bar(3);
foo(1);
bar(7);
foo(12);

refObject.value++;

bar(5);
foo(5);
