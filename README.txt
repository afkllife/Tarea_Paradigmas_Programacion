
===============================
PROYECTO: SISTEMA DE EVALUACIÓN DE PRUEBAS (TAXONOMÍA DE BLOOM)
ESTUDIANTES:	Martín Araya
		Carlos González
		Ignacio Benegas
===============================

1. DESCRIPCIÓN DEL PROYECTO
-------------------------------
Este sistema interactivo, desarrollado en Java con Swing, permite administrar y aplicar pruebas categorizadas 
por niveles cognitivos de la Taxonomía de Bloom. Soporta ítems de selección múltiple y verdadero/falso, 
cargados desde un archivo CSV, y entrega un análisis detallado de resultados al finalizar la evaluación.

2. ALCANCES Y RESTRICCIONES
-------------------------------
• Lenguaje: Java
• Framework: Swing (GUI)
• Arquitectura modular:
    - backend: lógica de negocio y procesamiento
    - frontend: interfaz gráfica (GUI)
• Comunicación por patrón observador (notificación-suscripción)
• Tipos de ítems:
    - Selección Múltiple
    - Verdadero/Falso
• Soporte para carga de ítems desde archivo externo (.csv o .txt)
• Validación de archivo con manejo de excepciones y mensajes de error claros
• Guardado en tiempo real de respuestas
• Navegación flexible entre preguntas (adelante y atrás)
• Resumen de resultados por:
    - Nivel de Bloom
    - Tipo de ítem
• Limitación:
    - No se gestiona historial de pruebas pasadas

3. INSTRUCCIONES DE EJECUCIÓN (INTELLIJ IDEA)
-------------------------------

3.1 Requisitos Previos
    - Java Development Kit (JDK) 8 o superior
    - IntelliJ IDEA (Community o Ultimate)

3.2 Importar el Proyecto en IntelliJ

    1. Abre IntelliJ IDEA
    2. Haz clic en "Open" y selecciona la carpeta raíz del proyecto
    3. IntelliJ detectará automáticamente el archivo pom.xml
    4. Si no lo hace, ve a:
       File > Project Structure > Modules > Add > Import Module from Existing Sources

3.3 Ejecutar la Aplicación

    1. En el panel izquierdo, busca la clase:
	Main
    2. Haz clic derecho sobre el archivo y selecciona:
       	Run 'Main.main()'

    → Esto iniciará la aplicación con la GUI de Swing.

3.4 Notas Adicionales

    • IntelliJ descargará automáticamente las dependencias Maven si es necesario.
    • Verifica el JDK en: File > Project Structure > Project SDK


4. CARGA DE ÍTEMS
-------------------------------
• Al iniciar la app, se muestra la Pantalla de Inicio.
• Presiona "Cargar Archivo de Ítems" y selecciona un archivo `.csv`.

→ Si el archivo es válido: comenzará la prueba.
→ Si hay errores: se mostrará un mensaje con detalles y no se iniciará la prueba.

5. FORMATO DEL ARCHIVO DE ÍTEMS
-------------------------------

• Separador de campos: `;` (punto y coma)
• Separador de opciones (MULTIPLE): `|` (barra vertical)

Estructura general por línea:
    tipo;enunciado;nivelBloom;tiempoEstimado;[info_específica_tipo]

CAMPOS:
-------
1. tipo:
    - MULTIPLE
    - VF

2. enunciado:
    - Texto de la pregunta

3. nivelBloom:
    - RECORDAR, ENTENDER, APLICAR, ANALIZAR, EVALUAR, CREAR

4. tiempoEstimado:
    - Entero (ej. 30 para 30 minutos)

5. información_específica_tipo:

    a. MULTIPLE:
        opciones separadas por `|`
        índice de la respuesta correcta (base 0)
        
        Ejemplo:
        MULTIPLE;¿Cuál es la capital de Francia?;RECORDAR;20;París|Londres|Madrid|Roma;0

    b. VF:
        true o false (respuesta correcta)

        Ejemplo:
        VF;El Sol es una estrella.;RECORDAR;10;true

EJEMPLOS DE ÍTEMS:
-------------------------------
MULTIPLE;¿Cuál de los siguientes no es un tipo de bucle en Java?;ENTENDER;30;for|while|foreach|until;3  
VF;Java es un lenguaje de programación orientado a objetos.;RECORDAR;15;true  
MULTIPLE;Dado el siguiente código Java:\n\nint x = 5;\nint y = 10;\nSystem.out.println(x + y);\n\n¿Cuál será la salida por consola?;APLICAR;60;510|15|Error de compilación|El programa no hace nada;1  
VF;Una interfaz en Java puede tener métodos con implementación completa a partir de Java 8.;ANALIZAR;45;true

===============================
FIN DEL DOCUMENTO
===============================
