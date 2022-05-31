package jpabook.jpashop.domain;

import org.springframework.data.annotation.CreatedDate;

import javax.persistence.*;
import java.time.LocalDateTime;

@Entity
@Table(name = "users")
public class Users {

    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long seq;

    @Column(length = 10, nullable = false)
    private String name;

    @Column(length = 10, nullable = false)
    private String email;

    @Column(length = 80, nullable = false)
    private String passwd;

    @Column(columnDefinition = "varchar(255) default null")
    private String profile_image_url;

    @Column(columnDefinition = "int not null default 0")
    private int login_count;

    @Column(columnDefinition = "datetime default null")
    private LocalDateTime last_login_at;

    @CreatedDate
    @Column(updatable = false)
    private LocalDateTime create_at;
}
