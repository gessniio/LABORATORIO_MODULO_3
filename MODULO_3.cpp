#include <iostream>   // Para cout y cin
#include <string>     // Para el tipo string
#include <limits>     // Para limpiar el buffer con numeric_limits
#include <cctype>     // Para toupper()

using namespace std;

// ============================================================
//  VARIABLE GLOBAL
//  Se declara aquí para que todas las funciones puedan
//  acceder a ella sin necesidad de pasarla como parámetro
//  en cada llamada. Representa el total de PCs disponibles.
// ============================================================
int totalEquiposDisponibles = 15;   // Empieza con 15 de 20 PCs libres


// ============================================================
//  DECLARACIONES (PROTOTIPOS) DE FUNCIONES
//  Se listan aquí antes del main() para que el compilador
//  sepa que existen aunque su código venga más abajo.
// ============================================================
void mostrarBienvenida();
bool validarHorario(int hora);
bool validarIDEstudiante(int id);
void asignarEquipo(int &totalEquipos);


// ============================================================
//  FUNCIÓN: mostrarBienvenida
//  Tipo de retorno : void  (no regresa ningún valor)
//  Parámetros      : ninguno
//  Propósito       : Imprime el banner institucional con el
//                    nombre de la universidad, un mensaje de
//                    bienvenida y las reglas del laboratorio.
// ============================================================
void mostrarBienvenida() {

    cout << "\n";
    cout <<       "\t################################################################\n";
    cout <<       "\t#                                                              #\n";
    cout <<       "\t#        UNIVERSIDAD NACIONAL ROSARIO CASTELLANOS (UNRC)       #\n";
    cout <<       "\t#                                                              #\n";
    cout <<       "\t#                  SISTEMA DE REGISTRO - MARVIN                #\n";
    cout <<       "\t#                                                              #\n";
    cout <<       "\t################################################################\n";
    cout << "\n==================================================================================\n";
    cout << "   MM           MM   AAAAAA   -RRRRRRRRRR  VV         VV   II   NNNN     NN\n";
    cout << "   MMMM       MMMM  AA    AA  -RR     RRR   VV       VV    II   NN NN    NN\n";
    cout << "   MM  MM    MM MM  AA    AA  -RR    RR      VV     VV     II   NN  NN   NN\n";
    cout << "   MM   MM MM   MM  AAAAAAAA  -RRRRRR         VV   VV      II   NN   NN  NN\n";
    cout << "   MM    MMM    MM  AA    AA  -RR    RRR       VV VV       II   NN    NN NN\n";
    cout << "   MM     M     MM  AA    AA  -RR      RRRR     VVV        II   NN     NNNN\n";
    cout << "====================================================================================\n";
    cout << "\n";
    cout << "  Sea bienvenido a la su sala laboratorio de computo.\n";
    cout << "  Por favor lea y respete las siguientes reglas de uso:\n";
    cout << "  YA QUE SI NO LAS RESPETA SERA SACADO DEL AREA\n";
    cout << "\n";
    cout << "  REGLAS DEL LABORATORIO:\n";
    cout << "  ---------------------------------------------------------------\n";
    cout << "  1. No se permite introducir alimentos ni bebidas al laboratorio, NO BEBIDAS ALCOHOLICAS \n";
    cout << "  2. El horario de uso es de 08:00 a 20:00 horas.\n";
    cout << "  3. Registra tu ingreso antes de usar cualquier equipo de computo.\n";
    cout << "  4. No instale programas sin autorizacion del Master.\n";
    cout << "  5. Al terminar, cierre su sesion y deje el equipo limpio.\n";
    cout << "  6. El uso de los equipos es unicamente con fines academicos.\n";
    cout << "  7. Si he visto viendo paginas indevidas sera expulsado del area.\n";
    cout << "  ---------------------------------------------------------------\n";
    cout << "\n";
}


// ============================================================
//  FUNCIÓN: validarHorario
//  Tipo de retorno : bool
//                    true  → la hora está dentro del horario
//                            permitido (08:00 a 20:00)
//                    false → la hora está fuera del rango o
//                            es inválida (fuera de 0-23)
//  Parámetros      : int hora  (paso por VALOR; la función
//                    recibe una copia y no modifica el original)
//  Propósito       : Verifica que la hora recibida sea un
//                    valor entre 0 y 23, y luego revisa si
//                    pertenece al horario de atención del lab.
// ============================================================
bool validarHorario(int hora) {

    // Primero verificamos que el valor sea una hora real (0-23)
    if (hora < 0 || hora > 23) {
        cout << "[ERROR] Hora invalida. Debe estar entre 0 y 23.\n";
        return false;   // Valor fuera del rango de horas del día
    }

    // Ahora verificamos si está dentro del horario del laboratorio
    if (hora >= 8 && hora <= 20) {
        return true;    // Hora dentro del horario permitido
    } else {
        // Mensaje claro para el usuario cuando está fuera de horario
        cout << "\n[AVISO] No se permite el uso de equipos fuera del horario\n";
        cout << "        establecido (08:00 - 20:00 hrs).\n";
        cout << "        Por favor regrese dentro del horario de atención.\n";
        return false;
    }
}


// ============================================================
//  FUNCIÓN: validarIDEstudiante
//  Tipo de retorno : bool
//                    true  → el ID es válido (entre 1 y 1000)
//                    false → el ID está fuera del rango
//  Parámetros      : int id  (paso por VALOR; la función
//                    trabaja con una copia del valor original)
//  Propósito       : Recibe el ID del estudiante y determina
//                    si es un valor mayor que 0 y menor o
//                    igual a 1000. Informa al usuario si no
//                    cumple con el rango establecido.
// ============================================================
bool validarIDEstudiante(int id) {

    // El ID debe ser mayor que 0 y menor o igual a 1000
    if (id > 0 && id <= 1000) {
        return true;    // ID dentro del rango válido
    } else {
        cout << "[ERROR] El ID del estudiante debe ser mayor a 0 "
             << "y menor o igual a 1000.\n";
        return false;
    }
}


// ============================================================
//  FUNCIÓN: asignarEquipo
//  Tipo de retorno : void  (no regresa ningún valor)
//  Parámetros      : int &totalEquipos  (paso por REFERENCIA)
//                    El símbolo & indica que se trabaja
//                    directamente sobre la variable original,
//                    no sobre una copia. Así el cambio que
//                    se hace aquí SÍ afecta a la variable
//                    fuera de la función.
//  Propósito       : Descuenta una unidad del contador de
//                    equipos disponibles cuando se asigna
//                    una PC a un usuario registrado.
// ============================================================
void asignarEquipo(int &totalEquipos) {

    // Solo se puede asignar si todavía hay equipos libres
    if (totalEquipos > 0) {
        totalEquipos--;   // Resta 1 al contador de disponibles
        cout << "  Equipo asignado correctamente.\n";
        cout << "  PCs disponibles restantes: " << totalEquipos << "\n";
    } else {
        // No hay equipos libres; se avisa al usuario
        cout << "[AVISO] No hay equipos disponibles en este momento.\n";
        cout << "        Por favor espere a que se libere un equipo.\n";
    }
}


// ============================================================
//  FUNCIÓN PRINCIPAL: main
//  Es el punto de entrada del programa. Contiene el menú
//  principal y llama a las funciones según sea necesario.
// ============================================================
int main() {

    // --------------------------------------------------------
    // VARIABLES LOCALES DEL MAIN
    // Estas variables solo existen dentro de main(); las
    // funciones anteriores tienen sus propias variables internas.
    // --------------------------------------------------------

    int idUsuario;      // ID del usuario que se va a registrar
    int numPC;          // Número de PC solicitada (1 al 20)
    int tiempoUso;      // Tiempo de uso en minutos
    int nivelEstudio;   // Nivel académico (1-6)
    int horaIngreso;    // Hora a la que entra el usuario (0-23)
    string nombreNivel; // Texto del nivel de estudio seleccionado
    int opcionMenu;     // Opción elegida en el menú principal
    char continuar;     // Respuesta S/N para seguir usando el sistema

    // Mostrar la bienvenida y reglas al arrancar el programa
    mostrarBienvenida();

    // --------------------------------------------------------
    // CICLO PRINCIPAL
    // Se ejecuta al menos una vez; pregunta si continuar al final
    // --------------------------------------------------------
    do {

        // ====================================================
        // MENÚ PRINCIPAL
        // ====================================================
        cout << "\n===========================================================================\n";
        cout << "                        REGISTRO - LABORATORIO                              \n";
        cout << "===========================================================================\n";
        cout << "  1. REGISTRO PARA NUEVO INGRESO\n";
        cout << "  2. CONSULTA DE DISPONIBILIDAD\n";
        cout << "  3. SALIR DEL SISTEMA\n";
        cout << "---------------------------------------------------------------------------\n";
        cout << "  Seleccione una opcion: ";
        cin  >> opcionMenu;

        // Si el usuario escribe letras en vez de número,
        // limpiamos el error para evitar un ciclo infinito
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcionMenu = -1;   // Valor que activa el default del switch
        }

        // ====================================================
        // SWITCH — decide qué hacer según la opción elegida
        // ====================================================
        switch (opcionMenu) {

            // ------------------------------------------------
            // OPCIÓN 1: REGISTRAR NUEVO INGRESO
            // ------------------------------------------------
            case 1:
                cout << "\n--- REGISTRO DE NUEVO INGRESO ---\n";

                // --- Captura y validación de la hora de ingreso ---
                // Se pide la hora y se llama a validarHorario()
                // Si no es válida, no se permite continuar con el registro
                cout << "Ingrese la hora de ingreso (0-23): ";
                cin  >> horaIngreso;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    horaIngreso = -1;   // Fuerza fallo en la validación
                }

                // Si el horario no es válido, saltamos el registro completo
                if (!validarHorario(horaIngreso)) {
                    cout << "  Registro cancelado por horario no permitido.\n";
                    break;   // Sale del case 1 y vuelve al menú
                }

                // --- Validación del ID del usuario ---
                // Usamos la función validarIDEstudiante()
                // El ciclo do-while repite hasta que el ID sea correcto
                do {
                    cout << "Ingrese el ID del estudiante (1-1000): ";
                    cin  >> idUsuario;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        idUsuario = 0;   // Fuerza a repetir el ciclo
                    }

                } while (!validarIDEstudiante(idUsuario));
                // El ciclo continúa mientras validarIDEstudiante devuelva false


                // --- Validación del número de PC (rango 1-20) ---
                do {
                    cout << "Ingrese el numero de PC solicitada (1-20): ";
                    cin  >> numPC;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        numPC = 0;
                    }

                    if (numPC < 1 || numPC > 20) {
                        cout << "[ERROR] El numero de PC debe estar entre 1 y 20. "
                             << "Intente de nuevo.\n";
                    }

                } while (numPC < 1 || numPC > 20);


                // --- Captura del tiempo de uso ---
                cout << "Ingrese el tiempo de uso en minutos: ";
                cin  >> tiempoUso;


                // --- Captura y decodificación del nivel de estudio ---
                cout << "\nNivel de estudio:\n";
                cout << "  1. Primaria\n";
                cout << "  2. Secundaria\n";
                cout << "  3. Preparatoria\n";
                cout << "  4. Universidad\n";
                cout << "  5. Posgrado\n";
                cout << "  6. Otro\n";
                cout << "  Seleccione: ";
                cin  >> nivelEstudio;

                // Traducimos el número al texto descriptivo
                switch (nivelEstudio) {
                    case 1: nombreNivel = "Primaria";      break;
                    case 2: nombreNivel = "Secundaria";    break;
                    case 3: nombreNivel = "Preparatoria";  break;
                    case 4: nombreNivel = "Universidad";   break;
                    case 5: nombreNivel = "Posgrado";      break;
                    case 6: nombreNivel = "Otro";          break;
                    default:
                        nombreNivel = "Desconocido";
                        cout << "[AVISO] Nivel no reconocido; "
                             << "se registrara como 'Desconocido'.\n";
                }

                // --- Asignación del equipo ---
                // Llamamos a asignarEquipo() pasando la variable GLOBAL
                // por referencia; la función restará 1 al contador
                asignarEquipo(totalEquiposDisponibles);

                // --- Resumen del registro ---
                cout << "\n--- REGISTRO GUARDADO EXITOSAMENTE ---\n";
                cout << "  Hora de ingreso : " << horaIngreso  << ":00 hrs\n";
                cout << "  ID de estudiante: " << idUsuario    << "\n";
                cout << "  PC asignada     : " << numPC        << "\n";
                cout << "  Tiempo de uso   : " << tiempoUso    << " minutos\n";
                cout << "  Nivel estudio   : " << nombreNivel  << "\n";
                cout << "--------------------------------------\n";
                break;

            // ------------------------------------------------
            // OPCIÓN 2: CONSULTAR DISPONIBILIDAD
            // ------------------------------------------------
            case 2:
                cout << "\n--- DISPONIBILIDAD DE EQUIPOS ---\n";
                cout << "  Total de PCs en el laboratorio : 20\n";
                cout << "  PCs disponibles                : "
                     << totalEquiposDisponibles << "\n";
                cout << "  PCs ocupadas                   : "
                     << (20 - totalEquiposDisponibles) << "\n";
                cout << "---------------------------------\n";
                break;

            // ------------------------------------------------
            // OPCIÓN 3: SALIR DEL SISTEMA
            // ------------------------------------------------
            case 3:
                cout << "\nCerrando el sistema. Hasta luego.\n";
                return 0;   // Termina el programa de forma limpia

            // ------------------------------------------------
            // DEFAULT — opción no reconocida
            // ------------------------------------------------
            default:
                cout << "\n[ERROR] Opcion invalida. "
                     << "Por favor elija 1, 2 o 3.\n";
                break;

        } // fin switch (opcionMenu)

        // ====================================================
        // PREGUNTA DE CONTINUIDAD
        // ====================================================
        cout << "\n¿Desea realizar otra operacion? (S/N): ";
        cin  >> continuar;
        continuar = toupper(continuar);   // Acepta 's' y 'S' por igual

    } while (continuar != 'N');   // Repite si no eligió salir

    // --------------------------------------------------------
    // MENSAJE DE CIERRE
    // --------------------------------------------------------
    cout << "\nSesion de administracion finalizada. Hasta pronto.\n\n";

    return 0;   // Código 0 = ejecución exitosa
}
