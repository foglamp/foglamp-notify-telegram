#ifndef _TELEGRAM_H
#define _TELEGRAM_H

#include <string>
#include <mutex>

/**
 * Telegram notification class that sends a message
 * via Telegram BOT API
 */
class Telegram
{       
	public: 
		Telegram(ConfigCategory *config);
		~Telegram();

		bool	notify(const std::string& notificationName,
				const std::string& triggerReason,
				const std::string& message);
		void	reconfigure(const std::string& newConfig);

	private:
		bool		m_enable;
		std::string	m_token;
		std::string	m_chatid;
		std::string	m_url;
		// Configuration mutex
		std::mutex	m_configMutex;
};
#endif
