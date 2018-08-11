# tesis-alarm

- Sobre esta aplicación

Esta aplicación es una alarma contra incendios, desarrollada sobre la plataforma Arduino. Es parte de un sistema de detección de incendios, en el cual se encuentra también una API Rest y una aplicación mobile.
Esta alarma monitorea las variables del entorno y envía una alerta de incendio a la API con la localización.
Para poder funcionar, requiere una serie de configuraciones, las cuales pueden ser proporcionadas por una aplicación Android, desarrollada especificamente para este propósito.


La aplicacion Android que configura esta alarma se encuentra en el siguiente repositorio: https://github.com/Mariani88/tesis-android-config

La API Rest se encuentra alojada en el siguiente repositorio: https://github.com/Mariani88/tesis-server

La aplicación mobile receptora de alertas se encuentra alojada en el siguiente repositorio: https://github.com/Mariani88/tesis-android

------------------------------------------------------------------------------------------------------------------------------

- Como clonar y compilar el proyecto proyecto

Luego de clonar este repositorio, se deben incorporar las librerias requeridas para la compilacion. Dado que no se incorporó un gestor de dependencias, pueden descargarse dichas librerías manualmente o a través del entorno de desarrollo oficial de Arduino. 
Para abrir el proyecto se recomienda usar otro entorno de desarrollo. Para este proyecto se usó Sloeber: http://www.baeyens.it/eclipse/

La idea sería la siguiente, instalar el IDE oficial de Arduino: https://www.arduino.cc/en/Main/Software y descargar las dependencias. Luego abrir el proyecto con Sloeber e incluir dichas librerías al proyecto.

Por último, puede utilizarse Sloeber para compilar el proyecto.

Las librerías son las siguientes:

+ DallasTempperature: https://github.com/milesburton/Arduino-Temperature-Control-Library
+ LiquidCrystal_I2C: https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
+ Wire: https://www.arduino.cc/en/Reference/Wire
+ MAX31850_OneWire: https://github.com/adafruit/MAX31850_OneWire
+ WiFiEsp:https://github.com/bportaluri/WiFiEsp




