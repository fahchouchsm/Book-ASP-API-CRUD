document.addEventListener('deviceready', onDeviceReady, false);

const apiKey = '05f3bf16944c43929ab172325241212';

// Map weather condition codes to Font Awesome icons
const weatherIcons = {
  1000: 'fa-sun', // Sunny
  1003: 'fa-cloud-sun', // Partly cloudy
  1006: 'fa-cloud', // Cloudy
  1009: 'fa-cloud', // Overcast
  1030: 'fa-smog', // Mist
  1063: 'fa-cloud-rain', // Patchy rain possible
  1066: 'fa-snowflake', // Patchy snow possible
  1069: 'fa-cloud-meatball', // Patchy sleet possible
  1072: 'fa-cloud-meatball', // Patchy freezing drizzle possible
  1087: 'fa-bolt', // Thundery outbreaks possible
  1114: 'fa-wind', // Blowing snow
  1117: 'fa-wind', // Blizzard
  1135: 'fa-smog', // Fog
  1147: 'fa-smog', // Freezing fog
  1150: 'fa-cloud-rain', // Patchy light drizzle
  1153: 'fa-cloud-rain', // Light drizzle
  1168: 'fa-cloud-rain', // Freezing drizzle
  1171: 'fa-cloud-rain', // Heavy freezing drizzle
  1180: 'fa-cloud-rain', // Patchy light rain
  1183: 'fa-cloud-rain', // Light rain
  1186: 'fa-cloud-showers-heavy', // Moderate rain at times
  1189: 'fa-cloud-showers-heavy', // Moderate rain
  1192: 'fa-cloud-showers-heavy', // Heavy rain at times
  1195: 'fa-cloud-showers-heavy', // Heavy rain
  1198: 'fa-cloud-rain', // Light freezing rain
  1201: 'fa-cloud-rain', // Moderate or heavy freezing rain
  1204: 'fa-cloud-meatball', // Light sleet
  1207: 'fa-cloud-meatball', // Moderate or heavy sleet
  1210: 'fa-snowflake', // Patchy light snow
  1213: 'fa-snowflake', // Light snow
  1216: 'fa-snowflake', // Patchy moderate snow
  1219: 'fa-snowflake', // Moderate snow
  1222: 'fa-snowflake', // Patchy heavy snow
  1225: 'fa-snowflake', // Heavy snow
  1237: 'fa-icicles', // Ice pellets
  1240: 'fa-cloud-showers-heavy', // Light rain shower
  1243: 'fa-cloud-showers-heavy', // Moderate or heavy rain shower
  1246: 'fa-cloud-showers-heavy', // Torrential rain shower
  1249: 'fa-cloud-meatball', // Light sleet showers
  1252: 'fa-cloud-meatball', // Moderate or heavy sleet showers
  1255: 'fa-snowflake', // Light snow showers
  1258: 'fa-snowflake', // Moderate or heavy snow showers
  1261: 'fa-icicles', // Light showers of ice pellets
  1264: 'fa-icicles', // Moderate or heavy showers of ice pellets
  1273: 'fa-bolt', // Patchy light rain with thunder
  1276: 'fa-bolt', // Moderate or heavy rain with thunder
  1279: 'fa-bolt', // Patchy light snow with thunder
  1282: 'fa-bolt', // Moderate or heavy snow with thunder
};

function onDeviceReady() {
  // Cordova is now initialized
  console.log('Running cordova-' + cordova.platformId + '@' + cordova.version);

  // Set up status bar (if plugin is installed)
  if (window.StatusBar) {
    StatusBar.styleLightContent();
    StatusBar.backgroundColorByHexString('#1e3c72');
  }

  // Hide splash screen (if plugin is installed)
  if (navigator.splashscreen) {
    navigator.splashscreen.hide();
  }

  getLocation();
}

function getWeatherIcon(conditionCode) {
  const iconClass = weatherIcons[conditionCode] || 'fa-cloud';
  return `<i class="fas ${iconClass} weather-icon"></i>`;
}

function getWeatherByCoords(lat, lon) {
  const apiUrl = `https://api.weatherapi.com/v1/forecast.json?key=${apiKey}&q=${lat},${lon}&days=7&aqi=no&alerts=no`;

  fetch(apiUrl)
    .then((response) => response.json())
    .then((data) => {
      document.getElementById('loading-overlay').style.display = 'none';

      // Update current weather
      document.querySelector('#temp').innerText = `${data.current.temp_c}°`;
      document.querySelector('#city').innerText = data.location.name;

      // Update current weather icon
      const conditionCode = data.current.condition.code.toString();
      const currentWeatherIcon = document.getElementById(
        'current-weather-icon',
      );
      currentWeatherIcon.className = `fas ${
        weatherIcons[conditionCode] || 'fa-cloud'
      } weather-icon`;
      currentWeatherIcon.style.animation = 'moveCloud 5s infinite ease-in-out';

      // Update temperature range
      const maxTemp = data.forecast.forecastday[0].day.maxtemp_c;
      const minTemp = data.forecast.forecastday[0].day.mintemp_c;
      document.querySelector(
        '#temperature-range',
      ).innerText = `${maxTemp}° / ${minTemp}°`;

      // Update last updated time
      const lastUpdated = new Date(data.current.last_updated);
      const updatedTime = `${lastUpdated.getHours()}:${String(
        lastUpdated.getMinutes(),
      ).padStart(2, '0')}`;
      document.querySelector(
        '#last-updated',
      ).innerText = `Dernière mise à jour: ${updatedTime}`;

      // Update hourly forecast
      const part3Divs = document.querySelector('.part3');
      part3Divs.innerHTML = '';
      data.forecast.forecastday[0].hour.forEach((hourData) => {
        const hourElement = document.createElement('div');
        const conditionCode = hourData.condition.code.toString();
        hourElement.innerHTML = `
                    <p>${hourData.time.slice(11, 16)}</p>
                    ${getWeatherIcon(conditionCode)}
                    <p>${hourData.temp_c}°</p>
                    <p><i class="fa-solid fa-droplet"></i> ${
                      hourData.humidity
                    }%</p>
                `;
        part3Divs.appendChild(hourElement);
      });

      // Update daily forecast
      const forecastTable = document.getElementById('forecast-table');
      forecastTable.innerHTML = '';
      data.forecast.forecastday.forEach((dayData, index) => {
        const date = new Date(dayData.date);
        const dayName = date.toLocaleDateString('fr-FR', {
          weekday: 'long',
        });
        const conditionCode = dayData.day.condition.code.toString();
        const row = document.createElement('tr');
        row.innerHTML = `
                    <td>${index === 0 ? "Aujourd'hui" : dayName}</td>
                    <td><i class="fa-solid fa-droplet"></i> ${
                      dayData.day.daily_chance_of_rain
                    }%</td>
                    <td>${dayData.day.maxtemp_c}°</td>
                    <td>${dayData.day.mintemp_c}°</td>
                `;
        forecastTable.appendChild(row);
      });

      // Update sunrise and sunset
      document.querySelector(
        '#sunrise',
      ).innerHTML = `<b>${data.forecast.forecastday[0].astro.sunrise}</b>`;
      document.querySelector(
        '#sunset',
      ).innerHTML = `<b>${data.forecast.forecastday[0].astro.sunset}</b>`;
    })
    .catch((error) => {
      console.error('Error fetching weather data: ', error);
      document.getElementById('loading-overlay').style.display = 'none';
      document.getElementById('city').innerText = 'Error loading weather data';
    });
}

function getLocation() {
  const options = {
    enableHighAccuracy: true,
    timeout: 10000,
    maximumAge: 0,
  };

  navigator.geolocation.getCurrentPosition(
    (position) => {
      const lat = position.coords.latitude;
      const lon = position.coords.longitude;
      getWeatherByCoords(lat, lon);
    },
    (error) => {
      console.error('Geolocation error:', error);
      document.getElementById('loading-overlay').style.display = 'none';
      document.getElementById('city').innerText =
        'Please enable location access';

      // Fallback to a default location (Paris)
      getWeatherByCoords(48.8566, 2.3522);
    },
    options,
  );
}
