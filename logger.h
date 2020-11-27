const char LOGGER_page[] PROGMEM = R"=====(
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
        <li class="nav-item active">
          <a class="nav-link" href="/logger">Logger<span class="sr-only">(current)</span></a>
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
      <tbody>
        <tr class="table-primary">
          <th scope="row"><h4><center>LOCUS Logger: </center></h4></th>
          <td><div class="btn-group btn-group-toggle" data-toggle="buttons">
            <label class="btn btn-success">
              <input type="checkbox" checked="" autocomplete="off"> Active
            </label>
          </div></td>
        <tr>
          <th scope="row">Logging Serial Number: </th>
          <td><span id="SerialID"></td>
        </tr>
        <tr>
          <th scope="row">Logging Type:</th>
          <td><span id="TypeID"></td>
        </tr>
        <tr>
          <th scope="row">Logging Mode:</th>
        </tr>
        <tr>
          <th scope="row">Logging Number:</th>
        </tr>
        <tr>
          <th scope="row">Logging Interval Setting:</th>
        </tr>
        <tr>
          <th scope="row">Logging Distance Setting:</th>
        </tr>
        <tr>
          <th scope="row">Logging Status:</th>
          <td><span id="StatusID"></td>
        </tr>
        <tr>
          <th scope="row">Logging Data Record Number</th>
          <td><span id="NumberID"></td>
        </tr>
        <tr>
          <th scope="row">Logging Capacity Used:</th>
          <td><div class="progress">
            <div class="progress-bar progress-bar-striped" id="CapacityBar" role="progressbar" style="width: 50%;" aria-valuenow="25" aria-valuemin="0" aria-valuemax="100"></div>
          </div></td>
          <td><span id="PercentID"></td>
        </tr>
        <tr>
          <th scope="row">Erase Logger Internal Flash Data:</th>
          <td><button type="button" class="btn btn-outline-primary" onclick="sendCommand(104)">ERASE FLASH</button></td>
        </tr>
        <tr>
          <th scope="row">Export Logger Data:</th>
          <td>
          <div class="form-group">
            <div class="input-group mb-3">
              <div class="custom-file">
                <input type="file" class="custom-file-input" id="inputGroupFile02">
                <label class="custom-file-label" for="inputGroupFile02">Choose file</label>
              </div>
              <div class="input-group-append">
                <span class="input-group-text">Save</span>
              </div>
            </div>
          </div>
        </td>
        </tr>
     </tbody>
    </table>
  </div>



<script>

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var jsonResponse  = JSON.parse(this.responseText);
      document.getElementById("SerialID").innerHTML = jsonResponse.serial
      document.getElementById("TypeID").innerHTML = jsonResponse.type
      document.getElementById("StatusID").innerHTML = jsonResponse.status
      document.getElementById("NumberID").innerHTML = jsonResponse.number
      document.getElementById("PercentID").innerHTML = jsonResponse.percent+"%"
      
      capacity_bar = document.getElementById("CapacityBar");
      capacity_bar.style = "width: "+jsonResponse.percent+"%;"

      }
    }
  xhttp.open("GET", "readLogger", true); //Handle readADC server on ESP
  xhttp.send();
  };
  
function sendCommand(command) {
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
