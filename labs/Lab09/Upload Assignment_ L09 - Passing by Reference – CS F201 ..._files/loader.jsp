




//sessionkey
var var_key = "55d0aba1-de26-11e9-80e9-02097508a7f2";
var var_dashboard_url = "https://uaf2.eesysoft.com";
var var_loadfile = "https://uaf2.eesysoft.com/loadFile";
var var_style_path = "https://uaf2.eesysoft.com/resources/";
var var_stamp = "20190923130143";
var var_eesy_build = "9349";
var var_eesy_dbUpdateCount = "1879";
var var_eesy_userUpdated = undefined;
var var_eesy_style_checksum = "d41d8cd98f00b204e9800998ecf8427e";
var var_show_tab_initial = true;
var var_show_tab = var_show_tab_initial;
var var_open_dashboard_in_new_window = false;
var var_tab_version = 2;
var var_proactive_version = 3;
var var_proactive_lms = "blackboard";
var var_open_as_chat = false;
var var_moveable_tab = true;
var var_language = -1;
var templates;
var waitforload = false;
var supportTabMinimized = undefined;
var scrollbarRightAdjust = '19px';
var supportTabMoveLimit = '50';
var eesy_minimizedTabWidth = '8px';
var eesy_maximizedTabWidth = '';
var attemptUnobscure = false;
var doNotLoadEngineForUserAgentPattern = 'not_in_use_05231;';
var var_eesy_hiddenHelpItems = undefined;
var var_eesy_sac = undefined;
var var_eesy_helpitemsSeen = undefined;
/////////////////////////////////////////////////////////////////////////////
// loader.js

var eesyRequestCount = 0;
var var_hasReportAccess = undefined;
var var_isExpert = undefined;

if(window.sessionStorage.eesysoft_session == undefined) {
	window.sessionStorage.eesysoft_session = new Date().getTime().toString();
}

if (!window.console) console = { log: function(){} };

function eesy_load_js(jsUrl) {
  var fileref = document.createElement("script");
  fileref.setAttribute("type", "text/javascript");
  fileref.setAttribute("src", jsUrl);
  document.getElementsByTagName("head")[0].appendChild(fileref);
}

//
// added checks to prevent the engine to load under ie < 11
//
function getIEVersion() {
  var ua = window.navigator.userAgent;
  var index = ua.indexOf("MSIE");
  
  if (index > 0) {
    return parseInt(ua.substring(index + 5, ua.indexOf(".", index)));
  } else if (!!navigator.userAgent.match(/Trident\/7\./)) {
    return 11;
  } else {
    return 0; //It is not IE
  }
}

function allowedBrowserBasedOnAgentPattern() {
  if (!window.doNotLoadEngineForUserAgentPattern || doNotLoadEngineForUserAgentPattern == "")
    return true;
  
  return !navigator.userAgent.match(doNotLoadEngineForUserAgentPattern); 
}


function allowedBrowser() {
  if (!allowedBrowserBasedOnAgentPattern())
    return false;
  
  var ieVersion = getIEVersion();
  return ieVersion == 0 || ieVersion >= 10;
}


if (allowedBrowser()) {
  eesy_load_js(var_dashboard_url + "/require-with-callback.jsp");
}

// This function is called directly from content
function handleHelpItem(itemId) {
	createHelpItemHandleEvent("helpitemHandle", {detail: {helpitemid: itemId}});
}

function handleHelpItemByGuid(guid) {
	createHelpItemHandleEvent("helpitemHandle", {detail: {helpitemGuid: guid}});
}

function handleHelpItemArticle(guid) {
	createHelpItemHandleEvent("helpitemArticleHandle", {detail: {helpitemGuid: guid}});
}


function createHelpItemHandleEvent(eventName, detailObj) {
  var event;
  if (window.CustomEvent) {
    event = new CustomEvent(eventName, detailObj);
  } else {
    event = document.createEvent('CustomEvent');
    event.initCustomEvent(eventName, true, true, detailObj);
  }
  document.dispatchEvent(event);
};


/**
 * Example:
 *
 * eesyRequire(['dep1', 'dep2'], function(dep1, dep2) {
 *   // init module
 * })
 */
function eesy_init_require() {
  window.eesyRequire = function(dependencies, initializer) {
    __eesyRequire(var_key, var_eesy_build, var_eesy_dbUpdateCount)(['require'], function(require) {
      require(dependencies, initializer);
    });
  };
  
  eesyRequire( ['jquery-private', 'sessionInfo', 'engine_core'], function($, sessionInfo, engineCore) {

    //$.support.cors = true;

    $(document).ajaxError(function(e, xhr, settings, exception) {
        console.log('error in: ' + settings.url + ' \n'+'error:\n' + exception );
    });

    //
    //  Load the CSS
    //
    eesy_load_css(var_style_path + "/proactiveresources/style.css"
        + "?styleChecksum=" + var_eesy_style_checksum);

    eesy_load_css(var_dashboard_url
        + "/resources/style_v2/eesysoft-template/assets/css/supportCenter.min.css"
        + "?v=" + var_eesy_build);

    eesy_load_css(var_style_path + "/override-proactive.css"
        + "?styleChecksum=" + var_eesy_style_checksum);


    //
    //  Load the templates
    //
    $.ajaxSetup({
      cache: true
    });

    var eesy_url_language = var_dashboard_url + '/rest/public/language/proactive?'
        + "v=" + var_eesy_build + "&"
        + "u=" + var_eesy_dbUpdateCount
        + "&languageId=" + var_language;

    eesy_initUserValues(function() {
      var eesy_url_load_templates = var_dashboard_url + "/Scripts/LoadTemplates.jsp"
        + "?callback=jsonTemplates"
        + "&language=" + var_language
        + "&styleChecksum=" + var_eesy_style_checksum;

      $.ajax({
        type: 'GET',
        url: eesy_url_load_templates,
        async: true,
        jsonpCallback: 'jsonTemplates',
        contentType: "application/json",
        dataType: 'jsonp',
        success: function(json) {
          templates = json;
          sessionInfo.init(var_dashboard_url, var_style_path, var_key, var_hasReportAccess);
          engineCore.start();
        },
        error: function(jqXHR, textStatus, errorThrown) {
          console.log("error:" + textStatus);
        }
      })
    });
  });
  
  function __eesyRequire(sessionKey, build, dbUpdateCount) {
	var staticJsLocation = (sessionStorage.DBG_LOCAL_STATIC_JS ? "http://127.0.0.1/" : "") + 'static/js';
    return eesy.requirejs.config({
      context: "eesy",
      urlArgs: "_=" + var_eesy_build,
      baseUrl: var_dashboard_url,
      waitSeconds: 200,
      paths: {

        // internal modules
        'field-decorator': 'resources/style_v2/js_require_modules/field-decorator',
        'sessionInfo': 'resources/style_v2/js_require_modules/sessionInfo',
        'supportCenter': 'resources/style_v2/js_require_modules/supportCenter',
        'system-information': 'resources/style_v2/js_require_modules/system-information',
        'utils': 'resources/style_v2/js_require_modules/utils',
        'contact-options': 'resources/style_v2/js_require_modules/contact-options',
        'contact-options-handler': 'resources/style_v2/js_require_modules/contact-options-handler',
        'session-events': 'resources/style_v2/js_require_modules/session-events',
        'templates': 'resources/style_v2/js_require_modules/templates',
        'osage-app': 'resources/style_v2/eesysoft-template/assets/js/app',
        'osage-results': 'resources/style_v2/eesysoft-template/assets/js/results',
        'osage-selector': 'resources/style_v2/eesysoft-template/assets/js/selector',
        'osage-contact': 'resources/style_v2/eesysoft-template/assets/js/contact',
        'context-probe': staticJsLocation + '/context-probe',
        'context-handling': staticJsLocation + '/context-handling',
        'monitor-handling': staticJsLocation + '/monitor-handling',
        'engine-state': staticJsLocation + '/engine-state',
        'found-items-handler': staticJsLocation + '/found-items-handler',
        'events-urlchange': staticJsLocation + '/events-urlchange',
        'events-domchange': staticJsLocation + '/events-domchange',
        'events-iframe': staticJsLocation + '/events-iframe',
        'context-tree-matcher': staticJsLocation + '/context-tree-matcher',
        'context-links': staticJsLocation + '/context-links',
        'keep-alive': staticJsLocation + '/keep-alive',
        'helpitem-handling': staticJsLocation + '/helpitem-handling',
        'presentation': staticJsLocation + '/presentation',
        'helpitem-loader': staticJsLocation + '/helpitem-loader',
        'mouse': staticJsLocation + '/mouse',
        'engine_core': staticJsLocation + '/engine_core',
        'expert-context-definer': staticJsLocation + '/expert-context-definer',
        'expert-tools': staticJsLocation + '/expert-tools',
        'element_templates': staticJsLocation + '/element_templates',
        'build_mode': staticJsLocation + '/build_mode',
        'expert-template-context-definer': staticJsLocation + '/expert-template-context-definer',
        'condition-matcher': staticJsLocation + '/condition-matcher',
		'expert-context-action-bar': staticJsLocation + '/expert-context-action-bar',
		'expert-element-highlighter': staticJsLocation + '/expert-element-highlighter',
        'support-tab': staticJsLocation + '/presentation/support-tab',
        'proactive-hints': staticJsLocation + '/presentation/proactive-hints',
        'presentation-helper': staticJsLocation + '/presentation/presentation-helper',
        'helpitem-visibility': staticJsLocation + '/presentation/helpitem-visibility',
        'eesy-timers': staticJsLocation + '/presentation/eesy-timers',
        'systrays': staticJsLocation + '/presentation/systrays',
        'hints': staticJsLocation + '/presentation/hints',
        'popups': staticJsLocation + '/presentation/popups',
        'quick-survey': staticJsLocation + '/presentation/quick-survey',
        'view-controller': staticJsLocation + '/presentation/view-controller',
        'helpitem-handlers': staticJsLocation + '/presentation/helpitem-handlers',
        'debug': staticJsLocation + '/debug',

        // resources
        'language-supportcenter': 'rest/public/language/supportcenter?languageId=' + var_language + '&s=' + window.sessionStorage.eesysoft_session,
        'language-cms': 'rest/public/language/cms?languageId=' + var_language + '&s=' + window.sessionStorage.eesysoft_session,
        'language': 'rest/public/language?languageId=' + var_language + '&s=' + window.sessionStorage.eesysoft_session,
        'settings-supportcenter': 'rest/settings/supportcenter?sessionkey=' + sessionKey + '&s=' + window.sessionStorage.eesysoft_session,
        'context-rule-tree': 'rest/public/context-rule-tree?v=' + build + "&u=" + dbUpdateCount + '&s=' + window.sessionStorage.eesysoft_session,
        'context-link-data': 'rest/public/context-links?v=' + build + "&u=" + dbUpdateCount + '&s=' + window.sessionStorage.eesysoft_session,
        'context-node-link-data': 'rest/public/contextNodeLinks?v=' + build + "&u=" + dbUpdateCount + '&s=' + window.sessionStorage.eesysoft_session,
        'user-context-variables': 'rest/userContext/userContextVariables?v=' + build + "&u=" + dbUpdateCount + '&sessionkey=' + sessionKey + '&courseId=' + (!(typeof window.eesy_course_id === 'undefined') ? window.eesy_course_id : -1)  + '&s=' + window.sessionStorage.eesysoft_session,
        'monitor-data': 'rest/public/monitors?v=' + build + "&u=" + dbUpdateCount  + '&s=' + window.sessionStorage.eesysoft_session,
        'hipa': 'rest/public/hipa?v=' + build + "&u=" + dbUpdateCount + '&s=' + window.sessionStorage.eesysoft_session,
        'page-templates':
            (sessionStorage.DBG_LOCAL_PAGE_TEMPLATES
                ? 'http://127.0.0.1/page_template?v=' + build + "&u=" + dbUpdateCount + '&sessionkey=' + sessionKey + '&s=' + window.sessionStorage.eesysoft_session
                : 'rest/public/templates/page_template?v=' + build + "&u=" + dbUpdateCount + '&sessionkey=' + sessionKey + '&s=' + window.sessionStorage.eesysoft_session),
        'element-templates':
            (sessionStorage.DBG_LOCAL_ELEMENT_TEMPLATES
                ? 'http://127.0.0.1/element_template?v=' + build + "&u=" + dbUpdateCount + '&sessionkey=' + sessionKey + '&s=' + window.sessionStorage.eesysoft_session
                : 'rest/public/templates/element_template?v=' + build + "&u=" + dbUpdateCount + '&sessionkey=' + sessionKey + '&s=' + window.sessionStorage.eesysoft_session),

        // external dependencies
        'jquery-private': 'dashboardstyles/base/style_v2/js_require_modules/jquery-private.jsp?noext',
        'mustachejs': 'dashboardstyles/base/style_v2/js_require_modules/mustachejs-private.jsp?noext',
        'bootstrap': 'bootstrap-js-as-define.jsp?noext',
        'datepicker': 'dashboardstyles/base/style_v2/js_require_modules/bootstrap-datepicker.jsp?noext',
        'bootstrap-switch': 'webjars/bootstrap-switch/3.3.2/js/bootstrap-switch.min',
          
        // require plugins
        'text': 'static/js/compiled/text',
        'json': 'static/js/compiled/json'
      },
      
      shim: {
        'jquery-private': {
          exports: '$'
        },
        bootstrap: {
          deps: ['jquery-private'] 
        },
        'bootstrap-switch': { deps: ['jquery-private'] },
        datepicker: {
          deps: ['bootstrap', 'jquery-private']
        }//,
//        mustachejs: {
//          exports: 'Mustache'
//        } 
        
      },
  
      map: {
        '*': { 'jquery': 'jquery-private' }
      }
    });
  }
}



function eesy_load_css(url) {
  if (document.createStyleSheet) {
    document.createStyleSheet(url);
  } else {
    var fileref = document.createElement("link");
    fileref.setAttribute("type", "text/css");
    fileref.setAttribute("href", url);
    fileref.setAttribute("rel", "stylesheet");
    document.getElementsByTagName("head")[0].appendChild(fileref);
  }
}

function eesy_set_role_inactive(rolename) {
  for (var prop in var_eesy_sac) { 
    if(var_eesy_sac[prop].rolename == rolename) {
      var_eesy_sac[prop].enabled = false;
    }
  }
}

function eesy_issueUserRequests() {
    var $ = $j_eesy;

    return [
        $.getJSON(var_dashboard_url + '/rest/userContext/hiddenHelpItems?sessionkey='
                + var_key + '&userUpdated=' 
                + var_eesy_userUpdated
                + '&s=' + window.sessionStorage.eesysoft_session, function(hiddenHelpItems) {
                
            var_eesy_hiddenHelpItems = hiddenHelpItems;
        }),
        
        $.getJSON(var_dashboard_url + '/rest/userContext/sessionAccessCache?sessionkey='
                + var_key
                + '&s=' + window.sessionStorage.eesysoft_session, function(sac) {
                
            var_eesy_sac = sac;
            //
            // check if any of the roles in the sac should be deactivated
            //
            if(!(typeof var_eesy_inactive_roles === 'undefined')) {
              for (var i=0; i < var_eesy_inactive_roles.length; i++) {
                eesy_set_role_inactive(var_eesy_inactive_roles[i]);
              }
            }
        }),
        
        $.getJSON(var_dashboard_url + '/rest/userContext/helpItemsSeen?sessionkey='
                + var_key + '&userUpdated=' 
                + var_eesy_userUpdated
                + '&s=' + window.sessionStorage.eesysoft_session, function(helpitemsSeen) {
                
            var_eesy_helpitemsSeen = helpitemsSeen;
        })
    ];
}

function eesy_initUserValues(onUserValuesInited) {
    var $ = $j_eesy;

    $.getJSON(var_dashboard_url + "/rest/userContext/userValues?sessionkey="
            + var_key + '&stamp=' 
            + var_stamp, function(userValues) {
            
        var_show_tab = (!!var_key) && (var_show_tab_initial || userValues.isShowTab);
        var_eesy_userUpdated = userValues.userUpdatedStamp;
        var_language = userValues.languageId;
        supportTabMinimized = userValues.isSupportTabMinimized;
        supportTabPosition = userValues.supportTabPosition;
        var_hasReportAccess = userValues.hasReportAccess;
        var_isExpert = userValues.isExpert;

        $.when.apply($, eesy_issueUserRequests()).then(onUserValuesInited);
    });
}
