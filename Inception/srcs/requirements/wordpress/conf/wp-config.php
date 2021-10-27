<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('WP_CACHE_KEY_SALT', 'hfunctio.42.fr');
define('WP_CACHE', true);
define( 'DB_NAME', 'main_database' );
define( 'DB_USER', 'hfunctio' );
define( 'DB_PASSWORD', '4321' );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'rh-8:H1(&pDyW2Ap:/RO-E?^;UCO~isp1OYRiSI=J9IGJ^iOd$:bzb^tq72F#yCb');
define('SECURE_AUTH_KEY',  '5/D)w^H|BN,zv6~0|Feaym|:`r@_SM ;4.vc|]/,}GTIHlH4~hg[05YwiR+91Uss');
define('LOGGED_IN_KEY',    'nlEf_hcBwu9-jOB4CKOOq+3CR|.EY`Qsok{5YBy-JKNJ +fYZuy{RAtxpDET8GWj');
define('NONCE_KEY',        's-K>Bi-^Ed]FpM^SwCu9eY4Vs#m*<v@A+QO/vCoGN%7~kHMMiC<!_$3|Fsx8ejh=');
define('AUTH_SALT',        '2dHfK58V3!%7B~<F}|xA_^$f-qA-#i-^UWje[@+i`$Zk4f~(U<$-]WsyvCI(h5.x');
define('SECURE_AUTH_SALT', 'tw] n(/5z?%PV#7m?BTeT^+-)3C]@r|Yl/->G*)D4;m4lD-#B/8jV<wI**`NamXU');
define('LOGGED_IN_SALT',   'OjW|-1X[v2{G4rV+sap0Fkeue2+CkrE`L@&c6`/gP5em7p6<Qv9W<cxWORiIA=m|');
define('NONCE_SALT',       '@n%>-Y{+ ]BlY9+u?2}pTM9gBQg1^|N%Mh3o{Su>:+ID*z0zNt].M{kb_^`>B$W8');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
