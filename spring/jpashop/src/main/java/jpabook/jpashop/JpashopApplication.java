package jpabook.jpashop;

import com.fasterxml.jackson.datatype.hibernate5.Hibernate5Module;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class JpashopApplication {

	public static void main(String[] args) {
		SpringApplication.run(JpashopApplication.class, args);
	}

	// 기본적으로 초기화 된 프록시 객체만 노출, 초기화 되지 않은 프록시 객체는 노출 안함 => 사실 엔티티 객체를 노출안할거기에 실무에 큰 지장은 없다!
	@Bean
	Hibernate5Module hibernate5Module() {

		Hibernate5Module hibernate5Module = new Hibernate5Module();
		// 설정을 통해 LAZY 로딩인 객체도 불러올수있다.
//		hibernate5Module.configure(Hibernate5Module.Feature.FORCE_LAZY_LOADING, true);
		return hibernate5Module;
	}
}
