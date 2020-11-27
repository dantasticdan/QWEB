const char CONFIG_page[] PROGMEM = R"=====(
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
        <li class="nav-item active">
          <a class="nav-link" href="/config">Configuration <span class="sr-only">(current)</span></a>
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
          <th scope="col">Command</th>
          <th scope="col">Execute</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">PMTK_SET_NMEA_BAUDRATE</th>
          <td><button type="button" class="btn btn-outline-primary" onclick="sendCommand(251488)">4800</button>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(251960)">9600</button>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(251144)">14400</button>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(251192)">19200</button>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(251384)">38400</button>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(251576)">57600</button>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(251115)">115200</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_POS_FIX</th>
          <td><div class="form-group">
             <label class="col-form-label" for="inputDefault">Default input</label>
             <input type="text" class="form-control" placeholder="Default input" id="inputDefault"></div>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(220)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_AL_DEE_CFG</th>
          <td><button type="button" class="btn btn-outline-primary" onclick="sendCommand(223)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_PERIODIC_MODE</th>
          <td>
            <p>Type:</p>
            <div class="form-group">
            <div class="custom-control custom-radio">
              <input type="radio" id="customRadio1" name="customRadio" class="custom-control-input" checked="">
              <label class="custom-control-label" for="customRadio1">Nomal Mode</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="customRadio2" name="customRadio" class="custom-control-input">
              <label class="custom-control-label" for="customRadio2">Periodic Backup Mode</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="customRadio3" name="customRadio" class="custom-control-input">
              <label class="custom-control-label" for="customRadio3">Periodic Standby Mode</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="customRadio4" name="customRadio" class="custom-control-input">
              <label class="custom-control-label" for="customRadio4">Perpetual Backup Mode</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="customRadio5" name="customRadio" class="custom-control-input">
              <label class="custom-control-label" for="customRadio5">AlwaysLocate Standby Mode</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="customRadio6" name="customRadio" class="custom-control-input">
              <label class="custom-control-label" for="customRadio6">AlwaysLocate Backup Mode</label>
            </div>
          </div>
          <div class="form-group">
            <label class="col-form-label" for="inputDefault">Run Time (ms):</label>
            <input type="text" class="form-control" placeholder="[Disable: 0-999], [Enable: 1000~518400000]" id="runTime"></div>
          <div class="form-group">
            <label class="col-form-label" for="inputDefault">Sleep Time (ms):</label>
            <input type="text" class="form-control"  placeholder="[Valid Range: 1000~518400000]"id="sleepTime"></div>
          <button type="button" class="btn btn-outline-primary" onclick="sendCommand(225)">SEND</button>
          </td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_SYNC_PPS_NMEA</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="PPSSyncSwitch">
              <label class="custom-control-label" for="PPSSyncSwitch">Enable Fix NMEA output to PPS</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(255)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_FLP_MODE</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="FLPSwitch">
              <label class="custom-control-label" for="FLPSwitch">Enable Fitness Low Power Mode (FLP)</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(255)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_PPS_CONFIG</th>
          <td>
            <p>Type:</p>
            <div class="form-group">
            <div class="custom-control custom-radio">
              <input type="radio" id="PPSRadio1" name="PPSRadio" class="custom-control-input" checked="">
              <label class="custom-control-label" for="PPSRadio1">Disable</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="PPSRadio2" name="PPSRadio" class="custom-control-input">
              <label class="custom-control-label" for="PPSRadio2">After First Fix</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="PPSRadio3" name="PPSRadio" class="custom-control-input">
              <label class="custom-control-label" for="PPSRadio3">3D Fix Only</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="PPSRadio4" name="PPSRadio" class="custom-control-input">
              <label class="custom-control-label" for="PPSRadio4">2D/3D Fix Only</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="PPSRadio5" name="PPSRadio" class="custom-control-input">
              <label class="custom-control-label" for="PPSRadio5">Always</label>
            </div>
          </div>
          <div class="form-group">
            <label class="col-form-label" for="inputPPSConfig">PPS Pulse Width (ms):</label>
            <input type="text" class="form-control" placeholder="[Valid Range: 2-998]" id="runTime"></div>
          <button type="button" class="btn btn-outline-primary" onclick="sendCommand(285)">SEND</button>
          </td>
        </tr>
        <tr>
          <th scope="row">PMTK_SET_AIC_ENABLED</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="AICSwitch">
              <label class="custom-control-label" for="AICSwitch">Enable AIC Function</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(286)">SEND</button></td>
        </tr>
        <tr>
          <tr class="table-primary">
          <th scope="row">PMTK_API_SET_DGPS_MODE</th>
          <td>
            <p>Mode:</p>
            <div class="form-group">
            <div class="custom-control custom-radio">
              <input type="radio" id="DGPSRadio1" name="DGPSRadio" class="custom-control-input" checked="">
              <label class="custom-control-label" for="DGPSRadio1">No DGPS Source</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="DGPSRadio2" name="DGPSRadio" class="custom-control-input">
              <label class="custom-control-label" for="DGPSRadio2">RTCM</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="DGPSRadio3" name="DGPSRadio" class="custom-control-input">
              <label class="custom-control-label" for="DGPSRadio3">SBAS (Including WAAS/EGNOS/GAGAN/MSAS)</label>
            </div>
          </div>
          <button type="button" class="btn btn-outline-primary" onclick="sendCommand(301)">SEND</button>
          </td>
        </tr>
        <tr>
          <tr class="table-primary">
          <th scope="row">PMTK_API_SET_SBAS_ENABLED</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="SBASSwitch">
              <label class="custom-control-label" for="SBASSwitch">Enable SBAS</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(313)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_API_SET_SUPPORT_QZSS_NMEA</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="QZSSNMEASwitch">
              <label class="custom-control-label" for="QZSSNMEASwitch">Enable QZSS NMEA Format</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(351)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_API_SET_STOP_QZSS</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="QZSSSwitch" checked="">
              <label class="custom-control-label" for="QZSSSwitch">Enable QZSS</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(351)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_API_SET_HDOP_THRESHOLD</th>
          <td><div class="form-group">
             <label class="col-form-label" for="HDOPThresh">HDOP Threshold:</label>
             <input type="text" class="form-control" placeholder="[0=Disabled]]" id="HDOPThresh"></div>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(356)">SEND</button></td>
        </tr>
        <tr>
           <th scope="row">PMTK_API_SET_STATIC_NAV_THD</th>
          <td><div class="form-group">
             <label class="col-form-label" for="StaticNavThresh">Speed Threshold (m/s):</label>
             <input type="text" class="form-control" placeholder="[Valid Range: 0-2]" id="StaticNavThresh"></div>
              <button type="button" class="btn btn-outline-primary" onclick="sendCommand(386)">SEND</button></td>
         </tr>
         <tr>
          <tr class="table-primary">
          <th scope="row">PMTK_EASY_ENABLE</th>
          <td><div class="form-group">
            <div class="custom-control custom-switch">
              <input type="checkbox" class="custom-control-input" id="EASYSwitch" checked="">
              <label class="custom-control-label" for="EASYSwitch">Enable EASY</label>
            </div>
            <button type="button" class="btn btn-outline-primary" onclick="sendCommand(869)">SEND</button></td>
        </tr>
        <tr>
          <th scope="row">PMTK_FR_MODE</th>
          <td>
            <p>Mode:</p>
            <div class="form-group">
            <div class="custom-control custom-radio">
              <input type="radio" id="FRRadio1" name="FRRadio" class="custom-control-input" checked="">
              <label class="custom-control-label" for="FRRadio1">Normal Mode (For general purpose)</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="FRRadio2" name="FRRadio" class="custom-control-input">
              <label class="custom-control-label" for="FRRadio2">Fitness Mode (For running and walking)</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="FRRadio3" name="FRRadio" class="custom-control-input">
              <label class="custom-control-label" for="FRRadio3">Aviation Mode (For high-dynamic large-acceleration
                movement</label>
            </div>
            <div class="custom-control custom-radio">
              <input type="radio" id="FRRadio4" name="FRRadio" class="custom-control-input">
              <label class="custom-control-label" for="FRRadio4">Balloon mode (For high-altitude vertical movement)</label>
            </div>
          </div>
          <button type="button" class="btn btn-outline-primary" onclick="sendCommand(886)">SEND</button>
          </td>
        </tr>
      </tbody>
    </table>
  </div> 

 <div>
 Command Response : <span id="Response">NA</span>
</div>


<script>

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var jsonResponse  = JSON.parse(this.responseText);
      //document.getElementById("Model").innerHTML = jsonResponse.dgps
      //document.getElementById("FW").innerHTML = jsonResponse.sbas
        if (jsonResponse.sbas == 1) {
          sbasswitch = document.getElementById("SBASSwitch");
          sbasswitch.checked = true;
        }
        if (jsonResponse.dgps == 1) {
          radiobtn = document.getElementById("DGPSRadio2");
          radiobtn.checked = true;
        }
        else if (jsonResponse.dgps == 2) {
          radiobtn = document.getElementById("DGPSRadio3");
          radiobtn.checked = true;
        }  
      }
    }
  xhttp.open("GET", "readADC", true); //Handle readADC server on ESP
  xhttp.send();
  };

function sendCommand(command) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Response").innerHTML =
      this.responseText;
      alert(this.responseText);
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
