/*
** EPITECH PROJECT, 2022
** project
** File description:
** Ressources
*/

#ifndef RESSOURCES_HPP_
#define RESSOURCES_HPP_

    #include "AThreeDimensionObject.hpp"

namespace Object {
    class Ressources : public AThreeDimensionObject {
        public:
            Ressources(Object::Render::MyModel &pathToModel, Object::Render::MyTexture &pathToRessources, Position const &position, Object::MAP_OBJECTS type);
            ~Ressources();

            void draw() override;

        protected:
        private:
    };
}

#endif /* !RESSOURCES_HPP_ */
