/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-martin.vanaud
** File description:
** server
*/

#include "server/server.h"
#include "server/communication/request/request.h"

void create_server(zappy_t *zappy)
{
    setup_server(zappy->server, zappy->options);
    initialise_all_clients_sockets(zappy->server);
    create_server_socket(zappy->server);
    allow_multiple_connections(zappy->server);

    configure_socket_type(zappy->server);
    bind_socket_to_server(zappy->server);

    while (1) {
        clear_socket_set(zappy->server);

        add_server_socket_to_set(zappy->server);
        add_client_socket_to_set(zappy->server);

        wait_for_connections(zappy->server);

        connect_client(zappy);
    }
}

void client_deconnected(zappy_t *zappy, int client_socket)
{
    close(zappy->server->sd->socket_descriptor);
    zappy->server->ss->client[client_socket] = 0;
}

void debug_server(zappy_t *zappy)
{
    printf("[DEBUG] server->port = %d\n", zappy->server->port);
    printf("[DEBUG] server->address_length = %d\n", zappy->server->address_length);

    printf("[DEBUG] server->ss->server = %d\n", zappy->server->ss->server);
    for (int index = 0; index < zappy->server->ss->max_client; index += 1)
        printf("[DEBUG] server->ss->client[%d] = %d\n", index, zappy->server->ss->client[index]);
    printf("[DEBUG] server->ss->max_client = %d\n", zappy->server->ss->max_client);

    printf("[DEBUG] server->sd->socket_descriptor = %d\n", zappy->server->sd->socket_descriptor);
    printf("[DEBUG] server->sd->max_socket_descriptor = %d\n", zappy->server->sd->max_socket_descriptor);
}

void free_server(zappy_t *zappy)
{
    free(zappy->server);
}