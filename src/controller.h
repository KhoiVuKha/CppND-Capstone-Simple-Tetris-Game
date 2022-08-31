#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tetromino.h"
#include "well.h"

class Controller {
   public:
    void HandleInput(bool &running, Tetromino &tetromino, const Well &well) const;

   private:
};

#endif // End of CONTROLLER_H