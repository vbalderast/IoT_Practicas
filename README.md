# IoT_Practicas
Nuestro codigo Client.py simula el cliente, primero rtenemos las variables de host y port y es ahí donde ingresas tu el puerto
a utilizar y la red, importamos el módulo socket y se crea un objeto socket para el cliente.
Se crea la conexion con el servidor y un bucle para que se retenga la conexion, posteriormente se instancia la entrada de datos
para que el cliente envie el mensaje al servidor, despues se utiliza el método send para enviar el mensaje, se cierra la instancia
del objeto que creamos y al final se imprime "conecion cerada"
Para el código Server.py vamos a importar el modulo del socket que creamos en el del cliente y después instanciamos unobjeto
para poder trabajar con el socket. 
Acepatamos la conexiones entarntes (en este caso las del cliente) con el metodo listen y se instancia cli para poder recibir los
datos que se envian desde el cliente. Se recibe el mensaje con el metodo recv, si fue exitoso que se reciban los datos se
imprime la ip y el host. Finalmente se devuelve el mensaje con el metodo send y se cierra la instancia del socket cliente y servidor.
Una vez que hayas ingresado el mismo puerto y el mismo network, debes correr primero el servior ya que el cliente lo necesita,
posteriormente en tu raspberry pi corres el cliente y aparecerá un mensaje que dice "Conectado al servidor" esto indica que 
ya va a estar conectado con el servidor. Después aparece un mensaje, este dice "Mensaje desde Clieente a Servidor", ahí 
debes de ingresar el mensaje que quieras enviar a tu servidor. Un Vez enviado, en el servidor aparecerá el mensaje y 
"Recuibo conexion de la ip:######### Puerto:######" con tu respectivo puerto e ip.

