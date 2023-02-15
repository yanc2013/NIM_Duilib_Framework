#ifndef UI_UTILS_ONSCREENKEYBOARDMANAGER_H_
#define UI_UTILS_ONSCREENKEYBOARDMANAGER_H_

#pragma once

namespace ui
{
/** @class OnScreenKeyboardManager
  * @brief Dиж?a?и╣?им1и╣идикидид
  * @copyright (c) 2018, NetEase Inc. All rights reserved
  * @author Redrain
  * @date 2018/08/28
  */
class UILIB_API OnScreenKeyboardManager : public virtual nbase::SupportWeakCallback
{
public:
	static OnScreenKeyboardManager* GetInstance();

	/**
	  * Dиж?a?и╣?ими║?бд??y?и▓??и║?
	  * @return bool
	  */
	bool IsVisible();

	/**
	  * ??и║?Dиж?a?и╣?им
	  * @param[in] show и║?бд???и║?
	  * @return void
	  */
	void ShowOSK(bool show);

private:
	OnScreenKeyboardManager();
	~OnScreenKeyboardManager() {};
	OnScreenKeyboardManager(const OnScreenKeyboardManager&) = delete;
	OnScreenKeyboardManager& operator = (const OnScreenKeyboardManager&) = delete;

	void TimerCallback();
	void StartTabTip();

private:
	bool m_bShow = false;
};
}
#endif //UI_UTILS_ONSCREENKEYBOARDMANAGER_H_