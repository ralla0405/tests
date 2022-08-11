package jpabook.jpashop.service;

import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.repository.ItemRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class ItemService {

    private final ItemRepository itemRepository;

    @Transactional
    public void saveItem(Item item) {
        itemRepository.save(item);
    }

    // merge 와 같은 동작
    @Transactional
    public Item updateItem(Long itemId, int price, String name, int stockQuantity) {

        Item findItem = itemRepository.findOne(itemId); // 영속상태인 객체
        // 변경감지를 위해선 set이 아니라 특정한 변수를 바꿔주는 함수를 만들어 사용해야한다.(추적할 수 있게 설계하자)
        findItem.setPrice(price);
        findItem.setName(name);
        findItem.setStockQuantity(stockQuantity);
        return findItem;
    }

    public List<Item> findItems() {
        return itemRepository.findAll();
    }

    public Item findOne(Long itemId) {
        return itemRepository.findOne(itemId);
    }
}
