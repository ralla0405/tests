package jpabook.jpashop.Controller;

import jpabook.jpashop.domain.item.Book;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.service.ItemService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
@RequiredArgsConstructor
public class ItemController {

    private final ItemService itemService;

    @GetMapping("/items/new")
    public String createForm(Model model) {
        model.addAttribute("form", new BookForm());
        return "items/createItemForm";
    }

    @PostMapping("/items/new")
    public String create(BookForm form) {

        // valid 검증 추가해서 테스트 해보자
        // 실무에선 createBook 생성자를 만들어서 설계하는게 좋다
        Book book = new Book();
        book.setName(form.getName());
        book.setPrice(form.getPrice());
        book.setStockQuantity(form.getStockQuantity());
        book.setAuthor(form.getAuthor());
        book.setIsbn(form.getIsbn());

        itemService.saveItem(book);
        return "redirect:/items";
    }

    @GetMapping("/items")
    public String list(Model model) {
        List<Item> items = itemService.findItems();
        model.addAttribute("items", items);
        return "items/itemList";
    }

    @GetMapping("items/{itemId}/edit")
    private String updateItemForm(@PathVariable("itemId") Long itemId, Model model) {

        Book item = (Book) itemService.findOne(itemId); // 간단한 예제를 위해 (Book만 사용) 캐스팅해서 사용

        BookForm form = new BookForm();
        form.setId(item.getId());
        form.setName(item.getName());
        form.setAuthor(item.getAuthor());
        form.setIsbn(item.getIsbn());
        form.setPrice(item.getPrice());
        form.setStockQuantity(item.getStockQuantity());

        model.addAttribute("form", form);
        return "items/updateItemForm";
    }

    @PostMapping("items/{itemId}/edit")
    public String updateItem(@ModelAttribute("form") BookForm form, @PathVariable Long itemId) {

        // 준영속 엔티티 (id 가 존재하므로)
//        Book book = new Book();
//        book.setId(form.getId());
//        book.setIsbn(form.getIsbn());
//        book.setPrice(form.getPrice());
//        book.setName(form.getName());
//        book.setAuthor(form.getAuthor());
//        book.setStockQuantity(form.getStockQuantity());
//        itemService.saveItem(book);

        itemService.updateItem(itemId, form.getPrice(), form.getName(), form.getStockQuantity());

        return "redirect:/items";
    }
}
