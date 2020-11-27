const char DEVICE_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <link rel="stylesheet" href="https://bootswatch.com/4/cosmo/bootstrap.min.css">
  <title>QWEB </title>
</head>
<body onload="getData()">
   <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
    <a class="navbar-brand" href="#">QWEB</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarColor01" aria-controls="navbarColor01" aria-expanded="true" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
  
    <div class="navbar-collapse collapse" id="navbarColor01" >
      <ul class="navbar-nav mr-auto">
        <li class="nav-item">
          <a class="nav-link" href="/">Status</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/config">Configuration</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/logger">Logger</a>
        </li>
        <li class="nav-item active">
          <a class="nav-link" href="/device">Device <span class="sr-only">(current)</span></a>
        </li>
      </ul>
    </div>
  </nav>
  
  <br>
  <div class="container TableContainer">
    <table class="table table-hover">
      <tbody>
        <tr class="table-primary">
          <th scope="row"><h4><center>Model: <span id="Model">N/A</span></center></h4></th>
          <tr class="table-primary">
           <td><h5><center>Firmware Version: <span id="FW">N/A</span></center></h5></td>
          </tr>
          <tr class="table-primary">
           <td><h5><center>Build #: <span id="Build">N/A</span></center></h5></td>
          </tr>
          <tr class="table-primary">
           <td><h5><center><span id="Response">N/A</span></center></h5></td>
          </tr>
     </tbody>
    </table>
  </div>

 <div class="container TableContainer">
    <table class="table table-hover">
      <thead>
        <tr class="table-primary">
          <th scope="col"><h4><center>PMTK Module Restart Commands</center></h4></th>
        </tr>
      </thead>
      <tbody>
        <tr class="table-primary">
          <td>
            <button type="button" class="btn btn-primary btn-lg btn-block" onclick="sendCommand(101)"> PMTK CMD: Hot Start</button>
          </td>
        </tr>
        <tr class="table-primary">
          <td>
             <button type="button" class="btn btn-primary btn-lg btn-block" onclick="sendCommand(102)"> PMTK CMD: Warm Start</button>
          </td>
        </tr>
        <tr class="table-primary">
          <td>
             <button type="button" class="btn btn-primary btn-lg btn-block" onclick="sendCommand(103)"> PMTK CMD: Cold Start</button>
          </td>
        </tr>
        <tr class="table-primary">
          <td>
             <button type="button" class="btn btn-primary btn-lg btn-block" onclick="sendCommand(104)"> PMTK CMD: Full Cold Start</button>
          </td>
        </tr>
      </tbody>
    </table>
  </div> 




<script>

//setInterval(function() {      // Call a function repetatively with 5 Second interval
 // getData();
//}, 1000); //1000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var jsonResponse  = JSON.parse(this.responseText);
      document.getElementById("Model").innerHTML = jsonResponse.model
      document.getElementById("FW").innerHTML = jsonResponse.fw
      document.getElementById("Build").innerHTML = jsonResponse.build
      }
    }
  xhttp.open("GET", "readADC", true); //Handle readADC server on ESP
  xhttp.send();
  };

function sendCommand(command) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      //document.getElementById("Response").innerHTML = this.responseText;
      //var jsonResponse  = JSON.parse(this.responseText);
      //document.getElementById("Model").innerHTML = jsonResponse.model
      //document.getElementById("FW").innerHTML = jsonResponse.fw
      //document.getElementById("Build").innerHTML = jsonResponse.build
    }
  };
  xhttp.open("GET", "readCommand?Response="+command, true);
  xhttp.send();
}

function refreshData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Response").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readCommand?Response="+command, true);
  xhttp.send();
}



</script>

  <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh" crossorigin="anonymous"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ" crossorigin="anonymous"></script>

</body>
</html>

)=====";
