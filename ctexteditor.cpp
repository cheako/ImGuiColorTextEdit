#include <string.h>
#include <stdlib.h>
#include "imgui.h"
#include "ctexteditor.h"
#include "TextEditor.h"

cTextEditor_LanguageDefinition_Builtins_t *cTextEditor_LanguageDefinition_Builtins() {
	static cTextEditor_LanguageDefinition_Builtins_t obj;
	static TextEditor::LanguageDefinition CPlusPlus;
	static TextEditor::LanguageDefinition HLSL;
	static TextEditor::LanguageDefinition GLSL;
	static TextEditor::LanguageDefinition C;
	static TextEditor::LanguageDefinition SQL;
	static TextEditor::LanguageDefinition AngelScript;
	static TextEditor::LanguageDefinition Lua;
	static TextEditor::LanguageDefinition Javascript;
	CPlusPlus = TextEditor::LanguageDefinition::CPlusPlus();
	obj.CPlusPlus.obj = &CPlusPlus;
	HLSL = TextEditor::LanguageDefinition::HLSL();
	obj.HLSL.obj = &HLSL;
	GLSL = TextEditor::LanguageDefinition::GLSL();
	obj.GLSL.obj = &GLSL;
	C = TextEditor::LanguageDefinition::C();
	obj.C.obj = &C;
	SQL = TextEditor::LanguageDefinition::SQL();
	obj.SQL.obj = &SQL;
	AngelScript = TextEditor::LanguageDefinition::AngelScript();
	obj.AngelScript.obj = &AngelScript;
	Lua = TextEditor::LanguageDefinition::Lua();
	obj.Lua.obj = &Lua;
	Javascript = TextEditor::LanguageDefinition::Javascript();
	obj.Javascript.obj = &Javascript;
	return &obj;
}

void cTextEditor_SetLanguageDefinition(cTextEditor_t m,
		const cTextEditor_LanguageDefinition_t aLanguageDef) {
	static_cast<TextEditor *>(m.obj)->SetLanguageDefinition(
			*(static_cast<TextEditor::LanguageDefinition *>(aLanguageDef.obj)));
}

cTextEditor_LanguageDefinition_t cTextEditor_GetLanguageDefinition(
		cTextEditor_t m) {
	cTextEditor_LanguageDefinition_t obj;
	/* TODO: Fix memory leak, return const like we used too. */
	TextEditor::LanguageDefinition *aLang = new TextEditor::LanguageDefinition;
	*aLang = static_cast<TextEditor *>(m.obj)->GetLanguageDefinition();
	obj.obj = aLang;
	return obj;
}

void cTextEditor_GetLanguageDefinition_destroy(
		cTextEditor_LanguageDefinition_t aLang) {
	delete static_cast<TextEditor::LanguageDefinition *>(aLang.obj);
}

cTextEditor_t cTextEditor_create() {
	cTextEditor_t m;
	TextEditor *obj;

	obj = new TextEditor();
	m.obj = obj;

	return m;
}

void cTextEditor_destroy(cTextEditor_t m) {
	delete static_cast<TextEditor *>(m.obj);
}

void cTextEditor_Render(cTextEditor_t m, const char *aTitle,
		struct ImVec2 aSize, bool aBorder) {
	static_cast<TextEditor *>(m.obj)->Render(aTitle, aSize, aBorder);
}

void cTextEditor_SetText(cTextEditor_t m, const char *aText) {
	static_cast<TextEditor *>(m.obj)->SetText(aText);
}

char *cTextEditor_GetText(cTextEditor_t m) {
	return strdup((static_cast<TextEditor *>(m.obj)->GetText()).c_str());
}

void cTextEditor_GetText_destroy(char *f) {
	free(f);
}
