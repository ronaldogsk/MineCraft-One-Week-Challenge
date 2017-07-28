#ifndef BLOCKDATABASE_H_INCLUDED
#define BLOCKDATABASE_H_INCLUDED

#include <memory>
#include <array>

#include "../../Util/Singleton.h"

#include "BlockTypes/BlockType.h"
#include "BlockId.h"

#include "../../Texture/TextureAtlas.h"

class BlockDatabase : public Singleton
{
    public:
        static BlockDatabase& get();

        const BlockType& getBlock(BlockId id) const;
        const BlockData& getData (BlockId id) const;

        TextureAtlas textureAtlas;

    private:
        BlockDatabase();

        std::array<std::unique_ptr<BlockType>,
                    (unsigned)BlockId::NUM_TYPES> m_blocks;
};

#endif // BLOCKDATABASE_H_INCLUDED
