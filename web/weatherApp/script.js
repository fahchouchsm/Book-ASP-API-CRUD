// Exécute la fonction principale quand la page est chargée
document.addEventListener('DOMContentLoaded', onPageLoad);

const apiKey = '05f3bf16944c43929ab172325241212';

// Liste des icônes météo associées aux codes
const weatherIcons = {
  1000: 'fa-sun', // Soleil
  1003: 'fa-cloud-sun', // Partiellement nuageux
  1006: 'fa-cloud', // Nuageux
  1009: 'fa-cloud', // Très nuageux
  1030: 'fa-smog', // Brouillard
  1063: 'fa-cloud-rain', // Pluie légère
  1066: 'fa-snowflake', // Neige légère
  1087: 'fa-bolt', // Orage
};

// Fonction appelée au chargement de la page
function onPageLoad() {
  getLocation();
}

// Retourne une icône météo correspondant au code
function getWeatherIcon(code) {
  if (weatherIcons[code]) {
    return `<i class="fas ${weatherIcons[code]} weather-icon"></i>`;
  } else {
    return `<i class="fas fa-cloud weather-icon"></i>`; // Par défaut, un nuage
  }
}

// Récupère la météo en fonction de la latitude et de la longitude
function getWeatherByCoords(lat, lon) {
  const url = `https://api.weatherapi.com/v1/forecast.json?key=${apiKey}&q=${lat},${lon}&days=7&aqi=no&alerts=no`;

  fetch(url)
    .then((response) => response.json())
    .then((data) => {
      document.getElementById('loading-overlay').style.display = 'none';

      document.querySelector('#temp').innerText = data.current.temp_c + '°';
      document.querySelector('#city').innerText = data.location.name;

      const code = data.current.condition.code;
      const currentWeatherIcon = document.getElementById(
        'current-weather-icon',
      );
      currentWeatherIcon.className =
        'fas ' + (weatherIcons[code] || 'fa-cloud') + ' weather-icon';

      document.querySelector('#temperature-range').innerText =
        data.forecast.forecastday[0].day.maxtemp_c +
        '° / ' +
        data.forecast.forecastday[0].day.mintemp_c +
        '°';

      const lastUpdated = new Date(data.current.last_updated);
      const updatedTime =
        lastUpdated.getHours() +
        ':' +
        String(lastUpdated.getMinutes()).padStart(2, '0');
      document.querySelector('#last-updated').innerText =
        'Dernière mise à jour: ' + updatedTime;

      // Météo heure par heure
      const part3Divs = document.querySelector('.part3');
      part3Divs.innerHTML = '';
      data.forecast.forecastday[0].hour.forEach((hourData) => {
        const hourElement = document.createElement('div');
        hourElement.innerHTML = `
          <p>${hourData.time.slice(11, 16)}</p>
          ${getWeatherIcon(hourData.condition.code)}
          <p>${hourData.temp_c}°</p>
          <p><i class="fa-solid fa-droplet"></i> ${hourData.humidity}%</p>
        `;
        part3Divs.appendChild(hourElement);
      });

      // Prévisions pour les prochains jours
      const forecastTable = document.getElementById('forecast-table');
      forecastTable.innerHTML = '';
      data.forecast.forecastday.forEach((dayData, index) => {
        const date = new Date(dayData.date);
        const dayName = date.toLocaleDateString('fr-FR', { weekday: 'long' });

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

      document.querySelector('#sunrise').innerHTML =
        '<b>' + data.forecast.forecastday[0].astro.sunrise + '</b>';
      document.querySelector('#sunset').innerHTML =
        '<b>' + data.forecast.forecastday[0].astro.sunset + '</b>';
    })
    .catch((error) => {
      console.error('Erreur:', error);
      document.getElementById('loading-overlay').style.display = 'none';
      document.getElementById('city').innerText = 'Erreur de chargement';
    });
}

// Récupère la position de l'utilisateur
function getLocation() {
  if (navigator.geolocation) {
    navigator.geolocation.getCurrentPosition(
      function (position) {
        getWeatherByCoords(position.coords.latitude, position.coords.longitude);
      },
      function () {
        document.getElementById('loading-overlay').style.display = 'none';
        document.getElementById('city').innerText = 'Activez la localisation';
      },
    );
  } else {
    console.log('La géolocalisation n’est pas supportée');
  }
}
