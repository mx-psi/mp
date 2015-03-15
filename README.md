# Prácticas MP
Repositorio para las prácticas de Metodología de la Programación.

## ¿Cómo subir cosas?

Para empezar haz `cd` hasta la carpeta en la que quieras guardar el código.
A continuación haz:

```bash
	git clone https://github.com/pbaeyens/practicas-mp.git #nombre de la carpeta donde vas a guardar las cosas#
```

Se copiarán todos los archivos necesarios. Luego para subir cosas nuevas lo básico
son 4 comandos:

- `git add #nombre de archivo(s)#` Añade archivos para que se rastreen los cambios (sólo hace falta una vez).
- `git pull` Actualiza tus archivos con respecto al servidor.
- `git commit -am #mensaje#` Crea una actualización (*'commit'*) con todos los cambios
	realizados desde el último *commit*.
- `git push` Sube al servidor todos los *commits* que hayas hecho. **La primera vez**
	tienes que hacer `git push origin master`.

Lo he configurado para que ignore los `.o` y `.a`, así que no hay que preocuparse
de eso.

