/*
** EPITECH PROJECT, 2022
** project
** File description:
** set_request
*/

#include "ai_request.h"

void ai_set_request(zappy_t *zappy, void *data, int player_index)
{
    char *request = (char *)data;
    enum ITEM resource = (enum ITEM)get_resource_from_request(request);
    int x, y = 0;

    if (resource == -1)
        ai_response_ok_ko(zappy->server->socket_descriptor->socket_descriptor, false);
    else {
        if (zappy->client[player_index].player.resource_inventory[resource].quantity > 0) {
            zappy->client[player_index].player.resource_inventory[resource].quantity -= 1;
            x = zappy->client[player_index].player.position.x;
            y = zappy->client[player_index].player.position.y;
            zappy->map->tiles[x][y].resources[resource].quantity += 1;
            // UPDATE MAP TILE IN GUI
            ai_response_ok_ko(zappy->server->socket_descriptor->socket_descriptor, true);
        } else
            ai_response_ok_ko(zappy->server->socket_descriptor->socket_descriptor, false);
    }
}