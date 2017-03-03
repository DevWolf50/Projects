/**
 * Sorting and counting modules in javascript
 *
 */

 "use strict";

 function find(needle, haystack) {
   var haystackLength = haystack.length;

   function sort() {
     //Counting Sort
     var maxLength = 1000;
     var sorted = [];
     var countArray = (function buildCountArray(length) {
       var array = [];
       for(i = 0; i < length; i++) {
         array[i] = 0;
       }
       return array;
     })(maxLength);

     for( let i = 0, n = haystackLength; i < n; i++ ) {
       countArray[haystack[i]]++;
     }
     for( let i = 0, n = countArray.length; i < n; i++ ) {
       countArray[ i + 1 ] =  countArray[i] + countArray[ i + 1 ];
     }

     for( let i = 0, n = haystackLength; i < n; i++ ) {
       sorted[countArray[haystack[i]] - 1] = haystack[i];
       countArray[haystack[i]]--;
     }

     haystack = sorted;
     console.log(haystack);
   }


   function search() {
     //Binary search
     var left = 0;
     var right = haystackLength - 1;

     return (function binarySearch(left, right) {


       if( right < left) {

         console.log("false");
         return false;
     }


       var mid = Math.trunc( left + ( right - left ) / 2 );
       console.log(haystack[mid]);

       if( needle === haystack[mid] ) {
         console.log("true");
         return true;

       } else if ( needle < haystack[mid] ) {

         right = mid - 1;
       }else {

         left = mid + 1;
       }

       console.log(left + ", " + right);

       return binarySearch( left, right );

     })(left, right);

   }

   var publicAPI = {
       sort: sort,
     search: search
   }

   return publicAPI;
 }

 var foo = find(6, [6,5,4,3,2,1,8,1,44,2,4,8,92,47,3,11,10]);

 foo.sort();
 foo.search();
