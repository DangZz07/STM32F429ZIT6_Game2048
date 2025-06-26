#ifndef TILE_HPP
#define TILE_HPP

#include <gui_generated/containers/TileBase.hpp>

class Tile : public TileBase
{
public:
    Tile();
    virtual ~Tile() {}
    void setValue(uint16_t value);
    virtual void initialize();
    uint16_t getValue() const;

protected:
};

#endif // TILE_HPP
