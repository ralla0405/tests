package jpabook.jpashop.respository.order.simplequery;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Repository;

import javax.persistence.EntityManager;
import java.util.List;

@Repository
@RequiredArgsConstructor
public class OrderSimpleQueryRepository {

    private final EntityManager em;

    // 화면에 맞춰져 있는 API 이다.
    public List<OrderSimpleQueryDto> findOrderDtos() {
        return em.createQuery(
    "select new jpabook.jpashop.respository.order.simplequery.OrderSimpleQueryDto(o.id, m.name, o.orderDate, o.status, d.address)" +
            " from Order o" +
            " join o.member m" +
            " join o.delivery d", OrderSimpleQueryDto.class)
        .getResultList();
    }
}
