#ifndef _DECKMENU_ITEM_H
#define _DECKMENU_ITEM_H

#include <string>
#include <JLBFont.h>
#include <JGui.h>
#include "DeckMenu.h"

using std::string;

#define SCALE_SELECTED		1.2f
#define SCALE_NORMAL		1.0f


class DeckMenuItem: public JGuiObject
{
 private:
  bool mHasFocus;
  DeckMenu* parent;
  int fontId;
  string mText;
  float mScale;
  float mTargetScale;

 public:
  string imageFilename;
  string desc;
  DeckMetaData *meta;

  DeckMenuItem(DeckMenu* _parent, int id, int fontId, string text, int x, int y, bool hasFocus = false, bool autoTranslate = false, DeckMetaData *meta = NULL);
  ~DeckMenuItem();
  int mX;
  int mY;

  void Relocate(int x, int y);
  int GetWidth();
  bool hasFocus();

  void RenderWithOffset(float yOffset);
  virtual void Render();
  virtual void Update(float dt);

  virtual void Entering();
  virtual bool Leaving(JButton key);
  virtual bool ButtonPressed();
  virtual ostream& toString(ostream& out) const;
  virtual bool getTopLeft(int& top, int& left) {top = mY; left = mX; return true;};
};

#endif