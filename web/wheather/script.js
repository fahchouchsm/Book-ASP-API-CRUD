const key = '05f3bf16944c43929ab172325241212';
const url = 'http://api.weatherapi.com/v1/forecast.json';
const locationCity = 'Oujda, Morocco';

document.addEventListener('DOMContentLoaded', () => {
  getWeather();
});

function getWeather() {
  let xhr = new XMLHttpRequest();
  xhr.open(
    'GET',
    `${url}?key=${key}&q=${locationCity}&days=7&aqi=no&alerts=no`,
    true,
  );

  xhr.onloadend = () => {
    const data = JSON.parse(xhr.response);
    console.log(data);
    updateWeatherUI(data);
    updateUI(data.forecast.forecastday);
  };

  xhr.send();
}

function updateWeatherUI(data) {
  document.getElementById('temperature').innerText = `${data.current.temp_c}°C`;
  document.getElementById('condition').innerText = data.current.condition.text;
  document.getElementById('humidity').innerText = `${data.current.humidity}%`;
  document.getElementById('wind').innerText = `${data.current.wind_kph} km/h`;
  document.getElementById(
    'location',
  ).innerText = `${data.location.name}, ${data.location.country}`;

  const icon = document.getElementById('weatherIcon');
  const iconUrl = `https:${data.current.condition.icon}`;
  icon.src = iconUrl;
}

function updateUI(forecast) {
  const forecastContainer = document.getElementById('forecast');
  forecastContainer.innerHTML = '';

  forecast.forEach((day) => {
    forecastContainer.innerHTML += `
      <li class="bg-white bg-opacity-30 p-3 rounded-lg min-w-[120px] text-center">
        <img src="https:${day.day.condition.icon}" alt="${day.day.condition.text}" class="mx-auto">
        <p class="text-white">${day.day.condition.text}</p>
        <p class="text-white">${day.day.maxtemp_c}°C / ${day.day.mintemp_c}°C</p>
      </li>
    `;
  });
}
