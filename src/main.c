#include <stdio.h>

// Función para imprimir una pregunta y evaluar la respuesta
int hacer_pregunta(const char *pregunta, const char *opciones[], int respuesta_correcta) {
    int respuesta;
    printf("%s\n", pregunta);
    for (int i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, opciones[i]);
    }
    printf("Introduce el número de tu respuesta: ");
    scanf("%d", &respuesta);

    if (respuesta == respuesta_correcta) {
        printf("¡Correcto!\n\n");
        return 1;
    } else {
        printf("Incorrecto. La respuesta correcta es %d) %s\n\n", respuesta_correcta, opciones[respuesta_correcta - 1]);
        return 0;
    }
}

// Función para jugar el cuestionario
void jugar_cuestionario() {
    int score = 0;

    const char *pregunta1 = "¿Cuál es la capital de Australia?";
    const char *opciones1[] = {"Sídney", "Melbourne", "Canberra", "Brisbane"};
    score += hacer_pregunta(pregunta1, opciones1, 3);

    const char *pregunta2 = "¿Quién pintó la Mona Lisa?";
    const char *opciones2[] = {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Rembrandt"};
    score += hacer_pregunta(pregunta2, opciones2, 3);

    const char *pregunta3 = "¿Qué país es conocido por la torre Eiffel?";
    const char *opciones3[] = {"Italia", "Francia", "España", "Alemania"};
    score += hacer_pregunta(pregunta3, opciones3, 2);

    const char *pregunta4 = "¿Cuál es el elemento químico con el símbolo 'O'?";
    const char *opciones4[] = {"Oro", "Osmio", "Oxígeno", "Oxalato"};
    score += hacer_pregunta(pregunta4, opciones4, 3);

    const char *pregunta5 = "¿En qué año comenzó la Primera Guerra Mundial?";
    const char *opciones5[] = {"1912", "1914", "1918", "1920"};
    score += hacer_pregunta(pregunta5, opciones5, 2);

    printf("Tu puntuación es: %d/5\n", score);
}

int main() {
    int opcion;

    while (1) {
        printf("Menú:\n");
        printf("1) Jugar\n");
        printf("2) Salir\n");
        printf("Introduce el número de tu elección: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            jugar_cuestionario();
        } else if (opcion == 2) {
            printf("¡Adiós!\n");
            break;
        } else {
            printf("Opción no válida. Por favor, inténtalo de nuevo.\n");
        }
    }

    return 0;
}
