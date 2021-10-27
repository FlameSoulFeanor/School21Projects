FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y default-mysql-server
EXPOSE 3306
COPY mariadb.sh /var/www/
RUN chmod +x /var/www/mariadb.sh
ENTRYPOINT [ "/var/www/mariadb.sh" ]
CMD [ "mysqld"]