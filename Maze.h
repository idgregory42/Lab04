#if !defined (MAZE_H)
#define MAZE_H

#include "CSC2110/Matrix.h"
using CSC2110::Matrix;
#include "Update.h"
#include "GUI/Drawable.h"

#include <gtkmm.h>
#include "StackLinked.h"
#include "Cell.h"


class Maze : public Drawable
{
   private:
      Matrix* maze;
      Update* gui;

      int width;
      int height;

      bool traverse();
      Cell* processBackTrack(StackLinked<Cell>* stack);
      void processSolution(StackLinked<Cell>* stack);
      bool isSolved(Cell* curr_cell, StackLinked<Cell>* stack);

      int WALL;
      int SPACE;
      int TRIED;
      int BACKTRACK;
      int PATH;

   public:
      Maze(Matrix* maze);
      virtual ~Maze();

      bool solve();
      void addListener(Update* gui);

      virtual void draw(Cairo::RefPtr<Cairo::Context> cr, int width, int height);
      virtual void mouseClicked(int x, int y);

};

#endif
