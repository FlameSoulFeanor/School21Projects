FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y openssl php-gd php-xml vim nginx sudo

RUN mkdir -p /run/nginx

COPY nginx.conf /etc/nginx/sites-available/default

RUN mkdir -p /var/www/front/
COPY index.html /var/www/front/
COPY style.css /var/www/front/                       

RUN chmod 777 /var/www/front/*
COPY nginx.sh /var/www/
RUN chmod +x /var/www/nginx.sh

ENTRYPOINT ["/var/www/nginx.sh"]
CMD ["nginx", "-g", "daemon off;"]