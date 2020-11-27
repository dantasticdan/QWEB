const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <link rel="stylesheet" href="https://bootswatch.com/4/cosmo/bootstrap.min.css">
  <title>QWEB </title>
</head>
<body>
  <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
    <a class="navbar-brand" href="#">QWEB</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarColor01" aria-controls="navbarColor01" aria-expanded="true" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
  
    <div class="navbar-collapse collapse" id="navbarColor01" >
      <ul class="navbar-nav mr-auto">
        <li class="nav-item active">
          <a class="nav-link" href="/">Status <span class="sr-only">(current)</span></a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/config">Configuration</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/logger">Logger</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/device">Device</a>
        </li>
      </ul>
    </div>
  </nav>
  
  <br>

  <div class="container TableContainer">
    <table class="table table-hover">
      <thead>
        <tr>
          <th scope="col">Parameter</th>
          <th scope="col">Value</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">Longitude</th>
          <td><span id="LonID"></td>
        </tr>
        <tr>
          <th scope="row">Latitude</th>
          <td><span id="LatID"></td>
        </tr>
        <tr>
          <th scope="row">Altitude (Sea Level)</th>
          <td><span id="AltID"></td>
        </tr>
        <tr>
          <th scope="row">Accuracy (HDOP)</th>
          <td><span id="AccID"></td>
        </tr>
        <tr>
          <th scope="row">Quality</th>
          <td><span id="QuaID"></td>
        </tr>
         <tr>
          <th scope="row">Satellites</th>
          <td><span id="SatID"></td>
        </tr>
        <tr>
          <th scope="row">Speed</th>
          <td><span id="SpeedID"></td>
        </tr>
        <tr>
          <th scope="row">Course</th>
          <td><span id="CourseID"></td>
        </tr>
        <tr>
          <th scope="row">Receiver Time</th>
          <td><span id="UTCTimeID"><div id="game"></td>
        </tr>
        <tr>
          <th scope="row">Local Time</th>
          <td><span id="LocalTimeID"></td>
        </tr>
      </tbody>
    </table>
  </div> 
  
  <div class="container MapContainer">
    <div id="googleMap" style="width:100%;height:400px;"></div>
  </div>

//  <footer class="mt-5 p-3 text-center bg-light">
//    Quectel &copy;
//  </footer>

<script>   // === AJAX Script ===

//var myLatLng = { lat: 0, lng: 0 };
//myLatLng = { lat: 50.91798, lng: -113.9527 };

setInterval(function() {      // Call a function repetatively with 5 Second interval
  getData();
}, 1000); //1000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var jsonResponse  = JSON.parse(this.responseText);
      document.getElementById("LatID").innerHTML = jsonResponse.latitude
      document.getElementById("LonID").innerHTML = jsonResponse.longitude
      document.getElementById("AltID").innerHTML = jsonResponse.altitude
      document.getElementById("AccID").innerHTML = jsonResponse.accuracy
      document.getElementById("QuaID").innerHTML = jsonResponse.quality
      document.getElementById("SatID").innerHTML = jsonResponse.sats
      document.getElementById("SpeedID").innerHTML = jsonResponse.speed
      document.getElementById("CourseID").innerHTML = jsonResponse.course
      //var du = Date.UTC(jsonResponse.years, (jsonResponse.months - 1), jsonResponse.days, jsonResponse.hours, jsonResponse.minutes, jsonResponse.seconds);
       var d = new Date(Date.UTC(2012, 02, 30))
       //var n = d.getUTCDate();
      //var d = new Date(2020, 11, jsonResponse.days, jsonResponse.hours, jsonResponse.minutes, jsonResponse.seconds);
      
      document.getElementById("UTCTimeID").innerHTML = jsonResponse.model
      var dl = new Date();
      document.getElementById("LocalTimeID").innerHTML = dl

    }
      //myLatLng = { lat: 50.91798, lng: -113.9527 };
      //myLatLng = new google.maps.LatLng(jsonResponse.latitude, jsonResponse.longitude);
      //alert(myLatLng);
   }

  xhttp.open("GET", "readADC", true); //Handle readADC server on ESP
  xhttp.send();
  
  };

  function myMap() {
    var myLatLng = { lat: 50.91798, lng: -113.9527 };
    //var myLatLng = { lat: jsonResponse.latitude, lng: jsonResponse.longitude };
    var mapProp= {center:myLatLng,zoom:18,};
    var map = new google.maps.Map(document.getElementById("googleMap"),mapProp);
    new google.maps.Marker({position: myLatLng,map});
    } 

</script>

  <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyAmMAGY4HDcJSna7i55FUeMEMfSA-XTASw&callback=myMap"></script>

  <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh" crossorigin="anonymous"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ" crossorigin="anonymous"></script>

</body>
</html>

)=====";
