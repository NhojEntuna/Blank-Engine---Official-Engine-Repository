s), 0.75) * 7.0);
  vec4 tmpvar_31;
  tmpvar_31 = textureCubeLod (unity_SpecCube0, worldNormal_21, tmpvar_30.w);
  vec3 tmpvar_32;
  tmpvar_32 = ((unity_SpecCube0_HDR.x * pow (tmpvar_31.w, unity_SpecCube0_HDR.y)) * tmpvar_31.xyz);
  if ((unity_SpecCube0_BoxMin.w < 0.99999)) {
    vec3 worldNormal_33;
    worldNormal_33 = tmpvar_20;
    if ((unity_SpecCube1_ProbePosition.w > 0.0)) {
      vec3 tmpvar_34;
      tmpvar_34 = normalize(tmpvar_20);
      vec3 tmpvar_35;
      tmpvar_35 = ((unity_SpecCube1_BoxMax.xyz - xlv_TEXCOORD8) / tmpvar_34);
      vec3 tmpvar_36;
      tmpvar_36 = ((unity_SpecCube1_BoxMin.xyz - xlv_TEXCOORD8) / tmpvar_34);
      bvec3 tmpvar_37;
      tmpvar_37 = greaterThan (tmpvar_34, vec3(0.0, 0.0, 0.0));
      float tmpvar_38;
      if (tmpvar_37.x) {
        tmpvar_38 = tmpvar_35.x;
      } else {
        tmpvar_38 = tmpvar_36.x;
      };
      float tmpvar_39;
      if (tmpvar_37.y) {
        tmpvar_39 = tmpvar_35.y;
      } else {
        tmpvar_39 = tmpvar_36.y;
      };
      float tmpvar_40;
      if (tmpvar_37.z) {
        tmpvar_40 = tmpvar_35.z;
      } else {
        tmpvar_40 = tmpvar_36.z;
      };
      vec3 tmpvar_41;
      tmpvar_41 = ((unity_SpecCube1_BoxMax.xyz + unity_SpecCube1_BoxMin.xyz) * 0.5);
      worldNormal_33 = (((
        (tmpvar_41 - unity_SpecCube1_ProbePosition.xyz)
       + xlv_TEXCOORD8) + (tmpvar_34 * 
        min (min (tmpvar_38, tmpvar_39), tmpvar_40)
      )) - tmpvar_41);
    };
    vec4 tmpvar_42;
    tmpvar_42.xyz = worldNormal_33;
    tmpvar_42.w = (pow ((1.0 - _Glossiness), 0.75) * 7.0);
    vec4 tmpvar_43;
    tmpvar_43 = textureCubeLod (unity_SpecCube1, worldNormal_33, tmpvar_42.w);
    tmpvar_17 = mix (((unity_SpecCube1_HDR.x * 
      pow (tmpvar_43.w, unity_SpecCube1_HDR.y)
    ) * tmpvar_43.xyz), tmpvar_32, unity_SpecCube0_BoxMin.www);
  } else {
    tmpvar_17 = tmpvar_32;
  };
  tmpvar_17 = (tmpvar_17 * tmpvar_13);
  vec3 viewDir_44;
  viewDir_44 = -(tmpvar_8);
  float tmpvar_45;
  tmpvar_45 = (1.0 - _Glossiness);
  vec3 tmpvar_46;
  tmpvar_46 = normalize((_WorldSpaceLightPos0.xyz + viewDir_44));
  float tmpvar_47;
  tmpvar_47 = max (0.0, dot (tmpvar_7, viewDir_44));
  float tmpvar_48;
  tmpvar_48 = max (0.0, dot (_WorldSpaceLightPos0.xyz, tmpvar_46));
  float tmpvar_49;
  tmpvar_49 = ((tmpvar_45 * tmpvar_45) * unity_LightGammaCorrectionConsts.w);
  float tmpvar_50;
  float tmpvar_51;
  tmpvar_51 = (10.0 / log2((
    ((1.0 - tmpvar_45) * 0.968)
   + 0.03)));
  tmpvar_50 = (tmpvar_51 * tmpvar_51);
  float x_52;
  x_52 = (1.0 - tmpvar_14);
  float x_53;
  x_53 = (1.0 - tmpvar_47);
  float tmpvar_54;
  tmpvar_54 = (0.5 + ((
    (2.0 * tmpvar_48)
   * tmpvar_48) * tmpvar_45));
  float x_55;
  x_55 = (1.0 - tmpvar_48);
  float x_56;
  x_56 = (1.0 - tmpvar_47);
  vec3 tmpvar_57;
  tmpvar_57 = (((tmpvar_10 * 
    (tmpvar_16 + (tmpvar_15 * ((
      (1.0 + ((tmpvar_54 - 1.0) * ((
        ((x_52 * x_52) * x_52)
       * x_52) * x_52)))
     * 
      (1.0 + ((tmpvar_54 - 1.0) * ((
        ((x_53 * x_53) * x_53)
       * x_53) * x_53)))
    ) * tmpvar_14)))
  ) + (
    (max (0.0, ((
      ((1.0/(((
        ((tmpvar_14 * (1.0 - tmpvar_49)) + tmpvar_49)
       * 
        ((tmpvar_47 * (1.0 - tmpvar_49)) + tmpvar_49)
      ) + 0.0001))) * (pow (max (0.0, 
        dot (tmpvar_7, tmpvar_46)
      ), tmpvar_50) * ((tmpvar_50 + 1.0) * unity_LightGammaCorrectionConsts.y)))
     * tmpvar_14) * unity_LightGammaCorrectionConsts.x)) * tmpvar_15)
   * 
    (tmpvar_11 + ((1.0 - tmpvar_11) * ((
      ((x_55 * x_55) * x_55)
     * x_55) * x_55)))
  )) + (tmpvar_17 * mix (tmpvar_11, vec3(
    clamp ((_Glossiness + (1.0 - tmpvar_12)), 0.0, 1.0)
  ), vec3(
    ((((x_56 * x_56) * x_56) * x_56) * x_56)
  ))));
  vec4 tmpvar_58;
  tmpvar_58.w = 1.0;
  tmpvar_58.xyz = tmpvar_57;
  c_1.w = tmpvar_58.w;
  c_1.xyz = (tmpvar_57 + (texture2D (_EmissionMap, xlv_TEXCOORD0.xy).xyz * _EmissionColor.xyz));
  vec4 xlat_varoutput_59;
  xlat_varoutput_59.xyz = c_1.xyz;
  xlat_varoutput_59.w = 1.0;
  gl_FragData[0] = xlat_varoutput_59;
}


#endif
�                                                      �:    D                POINT_COOKIE   SHADOWS_CUBE   SHADOWS_SOFTN  ps_4_0
eefiecedhhkiplpcjnlggklabiljpjefaeplaklaabaaaaaapealaaaaadaaaaaa
cmaaaaaajmaaaaaanaaaaaaaejfdeheogiaaaaaaadaaaaaaaiaaaaaafaaaaaaa
aaaaaaaaabaaaaaaadaaaaaaaaaaaaaaapaaaaaafmaaaaaaaaaaaaaaaaaaaaaa
adaaaaaaabaaaaaaapalaaaafmaaaaaaabaaaaaaaaaaaaaaadaaaaaaacaaaaaa
ahahaaaafdfgfpfaepfdejfeejepeoaafeeffiedepepfceeaaklklklepfdeheo
cmaaaaaaabaaaaaaaiaaaaaacaaaaaaaaaaaaaaaaaaaaaaaadaaaaaaaaaaaaaa
apaaaaaafdfgfpfegbhcghgfheaaklklfdeieefcbmalaaaaeaaaaaaamhacaaaa
fjaaaaaeegiocaaaaaaaaaaaapaaaaaafjaaaaaeegiocaaaabaaaaaaaiaaaaaa
fjaaaaaeegiocaaaacaaaaaaacaaaaaafjaaaaaeegiocaaaadaaaaaabkaaaaaa
fjaaaaaeegiocaaaaeaaaaaaaeaaaaaafkaaaaadaagabaaaaaaaaaaafkaaaaad
aagabaaaabaaaaaafkaaaaadaagabaaaacaaaaaafkaaaaadaagabaaaadaaaaaa
fkaaaaadaagabaaaaeaaaaaafibiaaaeaahabaaaaaaaaaaaffffaaaafibiaaae
aahabaaaabaaaaaaffffaaaafidaaaaeaahabaaaacaaaaaaffffaaaafidaaaae
aahabaaaadaaaaaaffffaaaafibiaaaeaahabaaaaeaaaaaaffffaaaagcbaaaad
lcbabaaaabaaaaaagcbaaaadhcbabaaaacaaaaaagfaaaaadpccabaaaaaaaaaaa
giaaaaacahaaaaaadiaaaaajhcaabaaaaaaaaaaaegiccaaaaaaaaaaaadaaaaaa
egiccaaaaaaaaaaaajaaaaaaaaaaaaahfcaabaaaaaaaaaaafgagbaaaaaaaaaaa
agaabaaaaaaaaaaadiaaaaahccaabaaaaaaaaaaackaabaaaaaaaaaaabkaabaaa
aaaaaaaadcaaaaalbcaabaaaaaaaaaaackiacaaaaaaaaaaaajaaaaaackiacaaa
aaaaaaaaadaaaaaaakaabaaaaaaaaaaaelaaaaafccaabaaaaaaaaaaabkaabaaa
aaaaaaaaapaaaaaiccaabaaaaaaaaaaapgipcaaaaaaaaaaaadaaaaaafgafbaaa
aaaaaaaaaaaaaaahbcaabaaaaaaaaaaabkaabaaaaaaaaaaaakaabaaaaaaaaaaa
aoaaaaahgcaabaaaaaaaaaaaagbbbaaaabaaaaaapgbpbaaaabaaaaaaefaaaaaj
pcaabaaaabaaaaaajgafbaaaaaaaaaaaeghobaaaaaaaaaaaaagabaaaaaaaaaaa
efaaaaajpcaabaaaacaaaaaajgafbaaaaaaaaaaaeghobaaaaeaaaaaaaagabaaa
aeaaaaaadcaaaaalccaabaaaaaaaaaaaakiacaaaabaaaaaaahaaaaaaakaabaaa
abaaaaaabkiacaaaabaaaaaaahaaaaaaaoaaaaakccaabaaaaaaaaaaaaceaaaaa
aaaaiadpaaaaiadpaaaaiadpaaaaiadpbkaabaaaaaaaaaaaaoaaaaaiecaabaaa
aaaaaaaackiacaaaabaaaaaaafaaaaaackbabaaaacaaaaaadiaaaaahhcaabaaa
abaaaaaakgakbaaaaaaaaaaaegbcbaaaacaaaaaadiaaaaahlcaabaaaabaaaaaa
fgafbaaaaaaaaaaaegaibaaaabaaaaaadiaaaaaihcaabaaaadaaaaaafgafbaaa
abaaaaaaegiccaaaaeaaaaaaabaaaaaadcaaaaakhcaabaaaadaaaaaaegiccaaa
aeaaaaaaaaaaaaaaagaabaaaabaaaaaaegacbaaaadaaaaaadcaaaaakhcaabaaa
adaaaaaaegiccaaaaeaaaaaaacaaaaaapgapbaaaabaaaaaaegacbaaaadaaaaaa
aaaaaaaihcaabaaaadaaaaaaegacbaaaadaaaaaaegiccaaaaeaaaaaaadaaaaaa
aaaaaaajhcaabaaaaeaaaaaaegacbaaaadaaaaaaegiccaiaebaaaaaaaaaaaaaa
aiaaaaaaaaaaaaakhcaabaaaafaaaaaaegacbaaaaeaaaaaaaceaaaaaaaaaaadm
aaaaaadmaaaaaadmaaaaaaaaefaaaaajpcaabaaaafaaaaaaegacbaaaafaaaaaa
eghobaaaacaaaaaaaagabaaaadaaaaaaaaaaaaakhcaabaaaagaaaaaaegacbaaa
aeaaaaaaaceaaaaaaaaaaalmaaaaaalmaaaaaadmaaaaaaaaefaaaaajpcaabaaa
agaaaaaaegacbaaaagaaaaaaeghobaaaacaaaaaaaagabaaaadaaaaaadgaaaaaf
ccaabaaaafaaaaaaakaabaaaagaaaaaaaaaaaaakhcaabaaaagaaaaaaegacbaaa
aeaaaaaaaceaaaaaaaaaaalmaaaaaadmaaaaaalmaaaaaaaaefaaaaajpcaabaaa
agaaaaaaegacbaaaagaaaaaaeghobaaaacaaaaaaaagabaaaadaaaaaadgaaaaaf
ecaabaaaafaaaaaaakaabaaaagaaaaaaaaaaaaakhcaabaaaagaaaaaaegacbaaa
aeaaaaaaaceaaaaaaaaaaadmaaaaaalmaaaaaalmaaaaaaaaefaaaaajpcaabaaa
agaaaaaaegacbaaaagaaaaaaeghobaaaacaaaaaaaagabaaaadaaaaaadgaaaaaf
icaabaaaafaaaaaaakaabaaaagaaaaaabaaaaaahecaabaaaaaaaaaaaegacbaaa
aeaaaaaaegacbaaaaeaaaaaaelaaaaaficaabaaaaaaaaaaackaabaaaaaaaaaaa
diaaaaaiicaabaaaaaaaaaaadkaabaaaaaaaaaaadkiacaaaacaaaaaaabaaaaaa
diaaaaahicaabaaaaaaaaaaadkaabaaaaaaaaaaaabeaaaaaomfbhidpdbaaaaah
pcaabaaaafaaaaaaegaobaaaafaaaaaapgapbaaaaaaaaaaadhaaaaanpcaabaaa
afaaaaaaegaobaaaafaaaaaaagiacaaaadaaaaaabiaaaaaaaceaaaaaaaaaiadp
aaaaiadpaaaaiadpaaaaiadpbbaaaaakicaabaaaaaaaaaaaegaobaaaafaaaaaa
aceaaaaaaaaaiadoaaaaiadoaaaaiadoaaaaiadodiaaaaaibcaabaaaabaaaaaa
ckaabaaaaaaaaaaadkiacaaaaaaaaaaaaiaaaaaaeeaaaaafecaabaaaaaaaaaaa
ckaabaaaaaaaaaaadiaaaaahhcaabaaaaeaaaaaakgakbaaaaaaaaaaaegacbaaa
aeaaaaaaefaaaaajpcaabaaaafaaaaaaagaabaaaabaaaaaaeghobaaaabaaaaaa
aagabaaaabaaaaaadiaaaaahecaabaaaaaaaaaaadkaabaaaaaaaaaaaakaabaaa
afaaaaaadiaaaaaihcaabaaaafaaaaaafgafbaaaadaaaaaaegiccaaaaaaaaaaa
amaaaaaadcaaaaakhcaabaaaafaaaaaaegiccaaaaaaaaaaaalaaaaaaagaabaaa
adaaaaaaegacbaaaafaaaaaadcaaaaakhcaabaaaafaaaaaaegiccaaaaaaaaaaa
anaaaaaakgakbaaaadaaaaaaegacbaaaafaaaaaaaaaaaaaihcaabaaaafaaaaaa
egacbaaaafaaaaaaegiccaaaaaaaaaaaaoaaaaaaefaaaaajpcaabaaaafaaaaaa
egacbaaaafaaaaaaeghobaaaadaaaaaaaagabaaaacaaaaaadiaaaaahecaabaaa
aaaaaaaackaabaaaaaaaaaaadkaabaaaafaaaaaadgcaaaaficaabaaaaaaaaaaa
ckaabaaaaaaaaaaaaaaaaaajhcaabaaaafaaaaaaegacbaaaadaaaaaaegiccaia
ebaaaaaaabaaaaaaaeaaaaaaaaaaaaajhcaabaaaadaaaaaaegacbaaaadaaaaaa
egiccaiaebaaaaaaadaaaaaabjaaaaaabaaaaaahbcaabaaaabaaaaaaegacbaaa
adaaaaaaegacbaaaadaaaaaaelaaaaafbcaabaaaabaaaaaaakaabaaaabaaaaaa
dcaaaaakccaabaaaaaaaaaaackaabaiaebaaaaaaabaaaaaabkaabaaaaaaaaaaa
akaabaaaabaaaaaadcaaaaakccaabaaaaaaaaaaadkiacaaaadaaaaaabjaaaaaa
bkaabaaaaaaaaaaadkaabaaaabaaaaaadcaaaaalccaabaaaaaaaaaaabkaabaaa
aaaaaaaackiacaaaaaaaaaaaakaaaaaadkiacaaaaaaaaaaaakaaaaaaaacaaaai
ccaabaaaaaaaaaaabkaabaiaebaaaaaaaaaaaaaaabeaaaaaaaaaiadpbaaaaaah
bcaabaaaabaaaaaaegacbaaaafaaaaaaegacbaaaafaaaaaaeeaaaaafbcaabaaa
abaaaaaaakaabaaaabaaaaaadcaaaaalhcaabaaaabaaaaaaegacbaiaebaaaaaa
afaaaaaaagaabaaaabaaaaaaegacbaiaebaaaaaaaeaaaaaabaaaaaahicaabaaa
abaaaaaaegacbaaaabaaaaaaegacbaaaabaaaaaaeeaaaaaficaabaaaabaaaaaa
dkaabaaaabaaaaaadiaaaaahhcaabaaaabaaaaaapgapbaaaabaaaaaaegacbaaa
abaaaaaadcaaaaaphcaabaaaacaaaaaaegacbaaaacaaaaaaaceaaaaaaaaaaaea
aaaaaaeaaaaaaaeaaaaaaaaaaceaaaaaaaaaialpaaaaialpaaaaialpaaaaaaaa
diaaaaahicaabaaaabaaaaaadkaabaaaacaaaaaaabeaaaaaaaaaaaedbaaaaaah
icaabaaaacaaaaaaegacbaaaacaaaaaaegacbaaaacaaaaaaeeaaaaaficaabaaa
acaaaaaadkaabaaaacaaaaaadiaaaaahhcaabaaaacaaaaaapgapbaaaacaaaaaa
egacbaaaacaaaaaabaaaaaahbcaabaaaabaaaaaaegacbaaaabaaaaaaegacbaaa
acaaaaaabaaaaaaiccaabaaaabaaaaaaegacbaiaebaaaaaaaeaaaaaaegacbaaa
acaaaaaadeaaaaahccaabaaaabaaaaaabkaabaaaabaaaaaaabeaaaaaaaaaaaaa
diaaaaahecaabaaaaaaaaaaackaabaaaaaaaaaaabkaabaaaabaaaaaadiaaaaai
ocaabaaaacaaaaaakgakbaaaaaaaaaaaagijcaaaaaaaaaaaajaaaaaadeaaaaah
ecaabaaaaaaaaaaaakaabaaaabaaaaaaabeaaaaaaaaaaaaacpaaaaafecaabaaa
aaaaaaaackaabaaaaaaaaaaadiaaaaahecaabaaaaaaaaaaackaabaaaaaaaaaaa
dkaabaaaabaaaaaabjaaaaafecaabaaaaaaaaaaackaabaaaaaaaaaaadiaaaaah
ecaabaaaaaaaaaaadkaabaaaaaaaaaaackaabaaaaaaaaaaadiaaaaahbcaabaaa
acaaaaaaakaabaaaaaaaaaaackaabaaaaaaaaaaadiaaaaahpccabaaaaaaaaaaa
fgafbaaaaaaaaaaaegaobaaaacaaaaaadoaaaaab                          $Globals�         unity_ColorSpaceLuminance                 0   	   _LightPos                 �      _LightColor                 �      unity_LightmapFade                 �      _LightMatrix0                �      UnityPerCamera�         _WorldSpaceCameraPos                 @      _ProjectionParams                 P      _ZBufferParams                 p      UnityLighting�        _LightPositionRange                       UnityShadows�        _LightShadowData                 �     unity_ShadowFadeCenterAndType                 �     UnityPerCamera2@         _CameraToWorld                    
      _CameraDepthTexture              _LightTextureB0            _ShadowMapTexture            _LightTexture0            _CameraNormalsTexture            $Globals              UnityPerCamera             UnityLighting             UnityShadows             UnityPerCamera2                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         �:                    POINT_COOKIE   SHADOWS_OFF0  ps_4_0_level_9_1
eefiecedefjdcpnblgmglfjfabobnjffdainoncaabaaaaaaomaiaaaaaeaaaaaa
daaaaaaadeadaaaaoiahaaaaliaiaaaaebgpgodjpmacaaaapmacaaaaaaacpppp
jiacaaaageaaaaaaaeaadeaaaaaageaaaaaageaaaeaaceaaaaaageaaadaaaaaa
aaababaaacacacaaabadadaaaaaaacaaabaaaaaaaaaaaaaaaaaaagaaabaaabaa
aaaaaaaaaaaaajaaabaaacaaaaaaaaaaaaaaanaaabaaadaaaaaaaaaaaaacpppp
fbaaaaafaeaaapkaaaaaiadpaaaaiaebaaaaaaaaaaaaaaaabpaaaaacaaaaaaia
aaaaaplabpaaaaacaaaaaaiaabaachlabpaaaaacaaaaaaiaacaacplabpaaaaac
aaaaaaiaadaacplabpaaaaacaaaaaaiaaeaacplabpaaaaacaaaaaaiaafaachla
bpaaaaacaaaaaajaaaaiapkabpaaaaacaaaaaajaabaiapkabpaaaaacaaaaaaji
acaiapkabpaaaaacaaaaaajaadaiapkaaiaaaaadaaaaciiaafaaoelaafaaoela
abaaaaacaaaacdiaaaaappiaceaaaaacabaachiaaeaaoelaaiaaaaadabaaciia
abaaoelbabaaoeiaacaaaaadabaaciiaabaappiaabaappiaaeaaaaaeacaachia
abaaoeiaabaappibabaaoelbabaaaaacadaacbiaacaapplaabaaaaacadaaccia
adaapplaabaaaaacadaaceiaaeaapplaaiaaaaadabaaciiaacaaoeiaadaaoeia
afaaaaadabaaciiaabaappiaabaappiaafaaaaadacaacbiaabaappiaabaappia
abaaaaacaaaaamiaadaaoekaacaaaaadacaacciaaaaappibaeaaaakaecaaaaad
aeaaapiaaaaaoeiaadaioekaecaaaaadafaaapiaafaaoelaacaioekaecaaaaad
acaaapiaacaaoeiaaaaioekaecaaaaadagaaapiaaaaaoelaabaioekaafaaaaad
abaaciiaaeaaaaiaafaappiaafaaaaadacaacoiaabaappiaabaablkaaiaaaaad
agaadiiaabaaoeiaadaaoeiaafaaaaadaaaacbiaacaaaaiaaeaaffkaabaaaaac
abaaahiaaaaaoekaaeaaaaaeabaachiaacaaoekaagaaoeiaabaaoeibafaaaaad
adaachiaagaaoeiaacaaoekaaeaaaaaeabaachiaaaaakkiaabaaoeiaaaaaoeka
afaaaaadabaachiaaaaaaaiaabaaoeiaaeaaaaaeabaaciiaaaaakkiaaaaappkb
aaaappkaaeaaaaaeaaaachiaadaaoeiaabaappiaabaaoeiaafaaaaadaaaachia
acaabliaaaaaoeiaafaaaaadaaaachiaagaappiaaaaaoeiaabaaaaacaaaaciia
aeaaaakaabaaaaacaaaicpiaaaaaoeiappppaaaafdeieefckmaeaaaaeaaaaaaa
clabaaaafjaaaaaeegiocaaaaaaaaaaaaoaaaaaafkaaaaadaagabaaaaaaaaaaa
fkaaaaadaagabaaaabaaaaaafkaaaaadaagabaaaacaaaaaafkaaaaadaagabaaa
adaaaaaafibiaaaeaahabaaaaaaaaaaaffffaaaafibiaaaeaahabaaaabaaaaaa
ffffaaaafidaaaaeaahabaaaacaaaaaaffffaaaafibiaaaeaahabaaaadaaaaaa
ffffaaaagcbaaaaddcbabaaaabaaaaaagcbaaaadhcbabaaaacaaaaaagcbaaaad
icbabaaaadaaaaaagcbaaaadicbabaaaaeaaaaaagcbaaaadpcbabaaaafaaaaaa
gcbaaaadhcbabaaaagaaaaaagfaaaaadpccabaaaaaaaaaaagiaaaaacaeaaaaaa
baaaaaahbcaabaaaaaaaaaaaegbcbaaaagaaaaaaegbcbaaaagaaaaaaefaaaaaj
pcaabaaaaaaaaaaaagaabaaaaaaaaaaaeghobaaaabaaaaaaaagabaaaadaaaaaa
efaaaaajpcaabaaaabaaaaaaegbcbaaaagaaaaaaeghobaaaacaaaaaaaagabaaa
acaaaaaadiaaaaahbcaabaaaaaaaaaaaakaabaaaaaaaaaaadkaabaaaabaaaaaa
diaaaaaihcaabaaaaaaaaaaaagaabaaaaaaaaaaaegiccaaaaaaaaaaaagaaaaaa
baaaaaahicaabaaaaaaaaaaaegbcbaaaafaaaaaaegbcbaaaafaaaaaaeeaaaaaf
icaabaaaaaaaaaaadkaabaaaaaaaaaaadiaaaaahhcaabaaaabaaaaaapgapbaaa
aaaaaaaaegbcbaaaafaaaaaabaaaaaaiicaabaaaaaaaaaaaegbcbaiaebaaaaaa
acaaaaaaegacbaaaabaaaaaaaaaaaaahicaabaaaaaaaaaaadkaabaaaaaaaaaaa
dkaabaaaaaaaaaaadcaaaaalhcaabaaaacaaaaaaegacbaaaabaaaaaapgapbaia
ebaaaaaaaaaaaaaaegbcbaiaebaaaaaaacaaaaaadgaaaaafbcaabaaaadaaaaaa
dkbabaaaadaaaaaadgaaaaafccaabaaaadaaaaaadkbabaaaaeaaaaaadgaaaaaf
ecaabaaaadaaaaaadkbabaaaafaaaaaabaaaaaahicaabaaaaaaaaaaaegacbaaa
acaaaaaaegacbaaaadaaaaaabacaaaahbcaabaaaabaaaaaaegacbaaaabaaaaaa
egacbaaaadaaaaaadiaaaaahicaabaaaaaaaaaaadkaabaaaaaaaaaaadkaabaaa
aaaaaaaadiaaaaahbcaabaaaacaaaaaadkaabaaaaaaaaaaadkaabaaaaaaaaaaa
aaaaaaajccaabaaaacaaaaaadkiacaiaebaaaaaaaaaaaaaaanaaaaaaabeaaaaa
aaaaiadpefaaaaajpcaabaaaacaaaaaaegaabaaaacaaaaaaeghobaaaadaaaaaa
aagabaaaaaaaaaaadiaaaaahicaabaaaaaaaaaaaakaabaaaacaaaaaaabeaaaaa
aaaaiaebefaaaaajpcaabaaaacaaaaaaegbabaaaabaaaaaaeghobaaaaaaaaaaa
aagabaaaabaaaaaadcaaaaamocaabaaaabaaaaaaagijcaaaaaaaaaaaajaaaaaa
agajbaaaacaaaaaaagijcaiaebaaaaaaaaaaaaaaacaaaaaadiaaaaaihcaabaaa
acaaaaaaegacbaaaacaaaaaaegiccaaaaaaaaaaaajaaaaaadcaaaaalocaabaaa
abaaaaaakgikcaaaaaaaaaaaanaaaaaafgaobaaaabaaaaaaagijcaaaaaaaaaaa
acaaaaaadiaaaaahocaabaaaabaaaaaapgapbaaaaaaaaaaafgaobaaaabaaaaaa
dcaaaaanicaabaaaaaaaaaaackiacaiaebaaaaaaaaaaaaaaanaaaaaadkiacaaa
aaaaaaaaacaaaaaadkiacaaaaaaaaaaaacaaaaaadcaaaaajocaabaaaabaaaaaa
agajbaaaacaaaaaapgapbaaaaaaaaaaafgaobaaaabaaaaaadiaaaaahhcaabaaa
aaaaaaaaegacbaaaaaaaaaaajgahbaaaabaaaaaadiaaaaahhccabaaaaaaaaaaa
agaabaaaabaaaaaaegacbaaaaaaaaaaadgaaaaaficcabaaaaaaaaaaaabeaaaaa
aaaaiadpdoaaaaabejfdeheomiaaaaaaahaaaaaaaiaaaaaalaaaaaaaaaaaaaaa
abaaaaaaadaaaaaaaaaaaaaaapaaaaaalmaaaaaaaaaaaaaaaaaaaaaaadaaaaaa
abaaaaaaapadaaaalmaaaaaaabaaaaaaaaaaaaaaadaaaaaaacaaaaaaahahaaaa
lmaaaaaaacaaaaaaaaaaaaaaadaaaaaaadaaaaaaapaiaaaalmaaaaaaadaaaaaa
aaaaaaaaadaaaaaaaeaaaaaaapaiaaaalmaaaaaaaeaaaaaaaaaaaaaaadaaaaaa
afaaaaaaapapaaaalmaaaaaaafaaaaaaaaaaaaaaadaaaaaaagaaaaaaahahaaaa
fdfgfpfaepfdejfeejepeoaafeeffiedepepfceeaaklklklepfdeheocmaaaaaa
abaaaaaaaiaaaaaacaaaaaaaaaaaaaaaaaaaaaaaadaaaaaaaaaaaaaaapaaaaaa
fdfgfpfegbhcghgfheaaklkl                          $Globals@        unity_ColorSpaceDielectricSpec                        _LightColor0                 `      _Color                 �   	   _Metallic                 �      _Glossiness                 �         _MainTex             _LightTextureB0            _LightTexture0            unity_NHxRoughness             $Globals                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         