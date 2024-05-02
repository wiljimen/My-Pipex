/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:56:29 by wiljimen          #+#    #+#             */
/*   Updated: 2024/05/02 15:00:02 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Para leer el comando que vamos a escribir, leeremos el segundo argumento y lo guardaremos en una string,
// luego, iremos a la carpeta /bin/ y buscaremos en aquella coincidencia en la que strncmp sea igual a 0.
// Eso quiere decir que será exactamente lo que buscamos.

#include "../includes/pipex.h"

int	main(void)
{
    int pid;

    // Crear un nuevo proceso hijo
    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso hijo
        fprintf(stderr, "Error al crear el proceso hijo\n");
        return 1;
    } else if (pid == 0) {
        // Código ejecutado por el proceso hijo
        printf("Soy el proceso hijo. Mi PID es %d. Mi padre es %d.\n", getpid(), getppid());
    } else {
        // Código ejecutado por el proceso padre
        printf("Soy el proceso padre. Mi PID es %d. El PID de mi hijo es %d.\n", getpid(), pid);
        // Esperar a que el proceso hijo termine (opcional)
        wait(NULL);
        printf("El proceso hijo ha terminado.\n");
    }

    return 0;
}
