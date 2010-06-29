
#ifndef __BUFFER_CACHE_UNLOCKED_HASH_MAP_HPP__
#define __BUFFER_CACHE_UNLOCKED_HASH_MAP_HPP__

#include <map>

template <class config_t>
struct unlocked_hash_map_t
{
public:
    typedef typename config_t::serializer_t serializer_t;
    typedef typename config_t::buf_t buf_t;
    
public:
    buf_t* find(block_id_t block_id) {
        typename ft_map_t::iterator block = ft_map.find(block_id);
        if(block == ft_map.end()) {
            return NULL;
        } else {
            return (*block).second;
        }
    }
    
    void set(block_id_t block_id, buf_t *block) {
        ft_map[block_id] = block;
    }
    
    void* erase(block_id_t block_id) {
        typename ft_map_t::iterator i = ft_map.find(block_id);
        void *block = (*i).second;
        ft_map.erase(i);
        return block;
    }

protected:
    typedef std::map<block_id_t, buf_t *> ft_map_t;
    ft_map_t ft_map;
};

#endif // __BUFFER_CACHE_UNLOCKED_HASH_MAP_HPP__

