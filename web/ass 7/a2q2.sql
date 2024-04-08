drop table student cascade;
drop table competition cascade;
drop table student_comp cascade;



--student(id,name,class)
create table student( stud_id int primary key, name varchar(30), class varchar(20));
insert into student values(1,'sanket','5th');
insert into student values(2,'vaishu','6th');



--competition(no,name,type)
create table competition(c_no int primary key, c_name varchar(30), type varchar(20));
insert into competition values(101,'ludo','Indoor');
insert into competition values(102,'cricket','Outdoor');




--manyTOmany
create table student_comp(stud_id int references student(stud_id) on delete cascade, c_no int references competition(c_no) on delete cascade, rank varchar(20), year int);
insert into student_comp values(2,102,'1st', 2020);
insert into student_comp values(1,101,'2nd', 2021);

