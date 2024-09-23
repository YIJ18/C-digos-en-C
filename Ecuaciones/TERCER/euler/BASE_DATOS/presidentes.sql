
CREATE TABLE presidentes (
  id int not null PRIMARY KEY AUTO_INCREMENT,
  ap_paterno varchar(30) default NULL,
  ap_materno varchar(30) default NULL,
  nombre varchar(50) default NULL,
  ciudad varchar(30) default NULL,
  estado varchar(15) default NULL,
  nacimiento date NOT NULL,
  muerte date default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;


INSERT INTO presidentes VALUES (1, 'Ju�rez','Garc�a','Benito','San Pablo Guelatao','Oaxaca','1806-03-21','1872-07-18');
INSERT INTO presidentes VALUES (2, 'Lerdo de Tejada','y Corral','Sebasti�n','Jalapa','Veracruz','1823-04-24','1889-04-21');
INSERT INTO presidentes VALUES (3, 'Iglesias','Inzurruaga','Jos� Mar�a','M�xico','D.F.','1823-01-05','1891-12-17');
INSERT INTO presidentes VALUES (4, 'M�ndez','S�nchez','Juan Nepomuceno','Tetela de Ocampo','Puebla','1820-07-02','1894-11-29');
INSERT INTO presidentes VALUES (5, 'Gonz�lez','Flores','Manuel del Refugio','Matamoros','Tamaulipas','1833-06-17','1893-05-08');
INSERT INTO presidentes VALUES (6, 'D�az','Mori','Jos� de la Cruz Porfirio','Oaxaca','Oaxaca','1830-09-15','1915-07-02');
INSERT INTO presidentes VALUES (7, 'Le�n','de la Barca','Francisco','Quer�taro','Quer�taro','1863-06-16','1939-09-23');
INSERT INTO presidentes VALUES (8, 'Madero','Gonz�lez','Francisco Ignacio','Parras','Coahuila','1873-10-30','1913-02-22');
INSERT INTO presidentes VALUES (9, 'Lascur�in','Paredes','Pedro Jos� Domingo de la Calzada Manuel Mar�a','M�xico','D.F.','1858-05-12','1952-06-21');
INSERT INTO presidentes VALUES (10, 'Huerta','M�rquez','Jos� Victoriano','Colotl�n','Jalisco','1845-03-23','1916-01-03');
INSERT INTO presidentes VALUES (11, 'Carbajal','','Francisco Sebasti�n','Campeche','Campeche','1870-12-09','1932-09-30');
INSERT INTO presidentes VALUES (12, 'Carranza','Garza','Venustiano','Cuatro Ci�negas','Coahuila','1859-12-29','1920-05-21');
INSERT INTO presidentes VALUES (13, 'Guti�rrez','Ortiz','Eulalio','Ramos Arizpe','Coahuila','1881-02-02','1939-08-12');
INSERT INTO presidentes VALUES (14, 'Gonz�lez','Garza','Roque','Saltillo','Coahuila','1885-03-23','1962-11-12');
INSERT INTO presidentes VALUES (15, 'Lagos','Ch�zaro','Francisco','Tlacotalpan','Veracruz','1878-09-30','1932-11-13');
INSERT INTO presidentes VALUES (16, 'de la Huerta','Marcor','Felipe Adolfo','Hermosillo','Sonora','1881-05-26','1955-07-09');
INSERT INTO presidentes VALUES (17, 'Obreg�n','Salido','�lvaro','Navojoa','Sonora','1880-02-19','1928-07-17');
INSERT INTO presidentes VALUES (18, 'El�as','Calles','Plutarco','Guaymas','Sonora','1877-09-25','1945-10-19');
INSERT INTO presidentes VALUES (19, 'Portes','Gil','Emilio','Ciudad Victoria','Tamaulipas','1890-10-03','1978-12-10');
INSERT INTO presidentes VALUES (20, 'Ortiz','Rubio','Pascual','Morelia','Michoac�n','1877-03-10','1963-11-04');
INSERT INTO presidentes VALUES (21, 'Rodr�guez','Luj�n','Abelardo','Guaymas','Sonora','1889-05-12','1967-02-13');
INSERT INTO presidentes VALUES (22, 'C�rdenas','Del R�o','L�zaro','Jiquilpan','Michoac�n','1895-05-21','1970-10-19');
INSERT INTO presidentes VALUES (23, '�vila','Camacho','Manuel','Tezuitl�n','Puebla','1897-04-24','1955-10-13');
INSERT INTO presidentes VALUES (24, 'Alem�n','Vald�s','Miguel','Sayula','Veracruz','1903-09-29','1983-05-14');
INSERT INTO presidentes VALUES (25, 'Ruiz','Cortines','Adolfo','Veracruz','Veracruz','1890-12-30','1973-12-03');
INSERT INTO presidentes VALUES (26, 'L�pez','Mateos','Adolfo','Atizap�n','M�xico','1910-05-26','1969-09-22');
INSERT INTO presidentes VALUES (27, 'D�az','Ordaz','Gustavo','Cd. Serdan','Puebla','1911-03-11','1979-07-15');
INSERT INTO presidentes VALUES (28, 'Echeverr�a','�lvarez','Luis','M�xico','D.F.','1922-01-17','2022-07-08');
INSERT INTO presidentes VALUES (29, 'L�pez','Portillo','Jos�','M�xico','D.F.','1920-06-16','2004-02-17');
INSERT INTO presidentes VALUES (30, 'De la Madrid','Hurtado','Miguel','Colima','Colima','1934-12-12','2012-04-01');
INSERT INTO presidentes VALUES (31, 'Salinas','de Gortari','Carlos','M�xico','D.F.','1948-04-03',NULL);
INSERT INTO presidentes VALUES (32, 'Zedillo','Ponce de Le�n','Ernesto','M�xico','D.F.','1951-12-17',NULL);
INSERT INTO presidentes VALUES (33, 'Fox','Quezada','Vicente','M�xico','D.F.','1942-07-02',NULL);
INSERT INTO presidentes VALUES (34, 'Calder�n','Hinojosa','Felipe','Morelia','Michoac�n','1962-08-18',NULL);
INSERT INTO presidentes VALUES (35, 'Pe�a','Nieto','Enrique','Atlacomulco','Mexico','1966-07-20',NULL);
INSERT INTO presidentes VALUES (36, 'L�pez','Obrador','Andr�s Manuel','Macuspana','Tabasco','1953-11-13',NULL);


