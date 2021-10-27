service mysql start
service php7.3-fpm start

# Configure a wordpress database

# Creating schema named with 'wordpress'
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
# Making account which can access to schema. We are making root acc. which can access to all tables
#in wordpress schema. And we skip pass with option 'mysql -u root --skip-password'
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
# If using INSERT,UPDATE or DELETE statements, u should tell the server to reload the tables
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
# If we dont provide a password to root user during the installation, it will use auto_socket for authentication.
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

nginx -g "daemon off;"