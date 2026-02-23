import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LinearRegression
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv("data.csv")

pd.set_option("display.max_columns", None)
pd.set_option("display.width", None)


# print(df.head())
# print(df.describe())

# print(df.isnull().sum())

df.fillna(df.mean(), inplace=True)

# traget is MEDV

# print(df.corr().round(2))
# print(df.head())

# division de donne

medv_corr = df.corr()[["MEDV"]].sort_values(by="MEDV", ascending=False)

sns.heatmap(medv_corr, annot=True, cmap="coolwarm", center=0)
plt.show()
df.corr().round(2)

from sklearn.preprocessing import StandardScaler
f = df[["RM"]]
t = df["MEDV"]

x_train, x_test, y_train, y_test = train_test_split(f, t, test_size=0.2, random_state=42)


scaler = StandardScaler()
x_train_scaled = scaler.fit_transform(x_train)
x_test_scaled = scaler.transform(x_test)

model = LinearRegression()
model.fit(x_train_scaled, y_train)
print("R² score:", model.score(x_test_scaled, y_test))

plt.scatter(f, t)
plt.plot(f, model.predict(f))
plt.xlabel("RM (number of rooms)")
plt.ylabel("MEDV (house price)")
plt.title("Regression line on scatter plot")
plt.show()