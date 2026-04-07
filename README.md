# MODULO_3
TAREA AUTENTICA MODULO 3

---

# 💻 Sistema de Registro de Laboratorio de Cómputo

## 📌 Descripción

Este proyecto es un sistema desarrollado en **C++** que permite gestionar el registro de usuarios en un laboratorio de cómputo.

El sistema simula el control de acceso a equipos, validando datos importantes como:

* Horario de ingreso
* ID del estudiante
* Número de equipo
* Disponibilidad de PCs

Además, muestra reglas del laboratorio y mantiene un conteo dinámico de equipos disponibles.

---

## 🎯 Objetivo

Facilitar la administración de un laboratorio de cómputo mediante un sistema sencillo en consola que:

* Controle el acceso de usuarios
* Evite registros fuera de horario
* Lleve control de equipos disponibles
* Mejore la organización del uso de recursos

---

## ⚙️ Características principales

✅ Menú interactivo en consola
✅ Validación de horario (08:00 - 20:00)
✅ Validación de ID de estudiante (1 - 1000)
✅ Control de equipos disponibles
✅ Uso de funciones modulares
✅ Manejo de errores con `cin.fail()`
✅ Uso de variables globales y paso por referencia

---

## 🧠 Estructura del programa

El sistema está dividido en funciones para mejorar la organización:

### 🔹 `mostrarBienvenida()`

Muestra:

* Banner institucional
* Reglas del laboratorio

---

### 🔹 `validarHorario(int hora)`

Valida:

* Que la hora esté entre 0 y 23
* Que esté dentro del horario permitido

Retorna:

* `true` → válido
* `false` → inválido

---

### 🔹 `validarIDEstudiante(int id)`

Verifica que el ID:

* Sea mayor a 0
* Sea menor o igual a 1000

---

### 🔹 `asignarEquipo(int &totalEquipos)`

* Reduce el número de equipos disponibles
* Usa **paso por referencia**
* Evita asignaciones si no hay PCs disponibles

---

### 🔹 `main()`

Contiene:

* Menú principal
* Lógica del sistema
* Control de flujo con `switch`
* Ciclo `do-while` para repetición

---

## 🖥️ Menú del sistema

El usuario puede elegir entre:

```
1. Registro para nuevo ingreso
2. Consulta de disponibilidad
3. Salir del sistema
```

---

## 📊 Lógica de funcionamiento

1. Se muestra la bienvenida
2. El usuario selecciona una opción
3. Si registra:

   * Se valida horario
   * Se valida ID
   * Se captura información
   * Se asigna equipo
4. Se actualiza el número de PCs disponibles
5. Se puede repetir el proceso

---

## 📦 Requisitos

* Compilador C++ (g++, MinGW, etc.)
* Editor de código (VS Code recomendado)

---

## ▶️ Cómo ejecutar

### 1. Compilar:

```bash
g++ main.cpp -o sistema
```

### 2. Ejecutar:

```bash
./sistema
```

---

## 🧩 Conceptos aplicados

* Programación estructurada
* Funciones
* Validación de datos
* Manejo de errores
* Paso por referencia
* Variables globales
* Uso de librerías estándar (`iostream`, `string`, `limits`, `cctype`)

---

## 🚀 Posibles mejoras

Aquí es donde puedes lucirte más en GitHub:

* Guardar registros en archivo (`.txt` o `.csv`)
* Interfaz gráfica (Qt o similar)
* Login de administrador
* Control por número específico de PC (no solo contador)
* Temporizador de uso
* Reportes de uso

---

## 👨‍💻 Autor

**Marvin Valdez**
Ingeniero en Sistemas, Electronica y Electromecanica | Redes | Ciberseguridad | IA

---

## 📄 Licencia

Este proyecto es de uso académico y educativo.

