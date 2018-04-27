#ifndef __CTEXTEDITOR_H__
#define __CTEXTEDITOR_H__
#include <cimgui.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *obj;
} cTextEditor_t;

typedef struct {
	void *obj;
} cTextEditor_LanguageDefinition_t;

typedef struct {
	cTextEditor_LanguageDefinition_t CPlusPlus;
	cTextEditor_LanguageDefinition_t HLSL;
	cTextEditor_LanguageDefinition_t GLSL;
	cTextEditor_LanguageDefinition_t C;
	cTextEditor_LanguageDefinition_t SQL;
	cTextEditor_LanguageDefinition_t AngelScript;
	cTextEditor_LanguageDefinition_t Lua;
	cTextEditor_LanguageDefinition_t Javascript;
} cTextEditor_LanguageDefinition_Builtins_t;

cTextEditor_LanguageDefinition_Builtins_t *cTextEditor_LanguageDefinition_Builtins();

void cTextEditor_SetLanguageDefinition(cTextEditor_t m,
		const cTextEditor_LanguageDefinition_t aLanguageDef);
cTextEditor_LanguageDefinition_t cTextEditor_GetLanguageDefinition(
		cTextEditor_t m);
void cTextEditor_GetLanguageDefinition_destroy(
		cTextEditor_LanguageDefinition_t aLang);

cTextEditor_t cTextEditor_create();
void cTextEditor_destroy(cTextEditor_t m);

void cTextEditor_Render(cTextEditor_t m, const char *aTitle,
		struct ImVec2 aSize, bool aBorder);
void cTextEditor_SetText(cTextEditor_t m, const char *aText);
char *cTextEditor_GetText(cTextEditor_t m);
void cTextEditor_GetText_destroy(char *);

#ifdef __cplusplus
}
#endif

#endif /* __CTEXTEDITOR_H__ */
